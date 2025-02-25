# frozen_string_literal: true
#
# = net/protocol.rb
#
#--
# Copyright (c) 1999-2004 Yukihiro Matsumoto
# Copyright (c) 1999-2004 Minero Aoki
#
# written and maintained by Minero Aoki <aamine@loveruby.net>
#
# This program is free software. You can re-distribute and/or
# modify this program under the same terms as Ruby itself,
# Ruby Distribute License or GNU General Public License.
#
# $Id: protocol.rb 66799 2019-01-12 21:02:26Z naruse $
#++
#
# WARNING: This file is going to remove.
# Do not rely on the implementation written in this file.
#

require 'socket'
require 'timeout'
require 'io/wait'

module Net # :nodoc:

  class Protocol   #:nodoc: internal use only
    private
    def Protocol.protocol_param(name, val)
      module_eval(<<-End, __FILE__, __LINE__ + 1)
        def #{name}
          #{val}
        end
      End
    end

    def ssl_socket_connect(s, timeout)
      if timeout
        while true
          raise Net::OpenTimeout if timeout <= 0
          start = Process.clock_gettime Process::CLOCK_MONOTONIC
          # to_io is required because SSLSocket doesn't have wait_readable yet
          case s.connect_nonblock(exception: false)
          when :wait_readable; s.to_io.wait_readable(timeout)
          when :wait_writable; s.to_io.wait_writable(timeout)
          else; break
          end
          timeout -= Process.clock_gettime(Process::CLOCK_MONOTONIC) - start
        end
      else
        s.connect
      end
    end
  end


  class ProtocolError          < StandardError; end
  class ProtoSyntaxError       < ProtocolError; end
  class ProtoFatalError        < ProtocolError; end
  class ProtoUnknownError      < ProtocolError; end
  class ProtoServerError       < ProtocolError; end
  class ProtoAuthError         < ProtocolError; end
  class ProtoCommandError      < ProtocolError; end
  class ProtoRetriableError    < ProtocolError; end
  ProtocRetryError = ProtoRetriableError

  ##
  # OpenTimeout, a subclass of Timeout::Error, is raised if a connection cannot
  # be created within the open_timeout.

  class OpenTimeout            < Timeout::Error; end

  ##
  # ReadTimeout, a subclass of Timeout::Error, is raised if a chunk of the
  # response cannot be read within the read_timeout.

  class ReadTimeout < Timeout::Error
    def initialize(io = nil)
      @io = io
    end
    attr_reader :io

    def message
      msg = super
      if @io
        msg = "#{msg} with #{@io.inspect}"
      end
      msg
    end
  end

  ##
  # WriteTimeout, a subclass of Timeout::Error, is raised if a chunk of the
  # response cannot be written within the write_timeout.  Not raised on Windows.

  class WriteTimeout < Timeout::Error
    def initialize(io = nil)
      @io = io
    end
    attr_reader :io

    def message
      msg = super
      if @io
        msg = "#{msg} with #{@io.inspect}"
      end
      msg
    end
  end


  class BufferedIO   #:nodoc: internal use only
    def initialize(io, read_timeout: 60, write_timeout: 60, continue_timeout: nil, debug_output: nil)
      @io = io
      @read_timeout = read_timeout
      @write_timeout = write_timeout
      @continue_timeout = continue_timeout
      @debug_output = debug_output
      @rbuf = ''.b
    end

    attr_reader :io
    attr_accessor :read_timeout
    attr_accessor :write_timeout
    attr_accessor :continue_timeout
    attr_accessor :debug_output

    def inspect
      "#<#{self.class} io=#{@io}>"
    end

    def eof?
      @io.eof?
    end

    def closed?
      @io.closed?
    end

    def close
      @io.close
    end

    #
    # Read
    #

    public

    def read(len, dest = ''.b, ignore_eof = false)
      LOG "reading #{len} bytes..."
      read_bytes = 0
      begin
        while read_bytes + @rbuf.size < len
          s = rbuf_consume(@rbuf.size)
          read_bytes += s.size
          dest << s
          rbuf_fill
        end
        s = rbuf_consume(len - read_bytes)
        read_bytes += s.size
        dest << s
      rescue EOFError
        raise unless ignore_eof
      end
      LOG "read #{read_bytes} bytes"
      dest
    end

    def read_all(dest = ''.b)
      LOG 'reading all...'
      read_bytes = 0
      begin
        while true
          s = rbuf_consume(@rbuf.size)
          read_bytes += s.size
          dest << s
          rbuf_fill
        end
      rescue EOFError
        ;
      end
      LOG "read #{read_bytes} bytes"
      dest
    end

    def readuntil(terminator, ignore_eof = false)
      begin
        until idx = @rbuf.index(terminator)
          rbuf_fill
        end
        return rbuf_consume(idx + terminator.size)
      rescue EOFError
        raise unless ignore_eof
        return rbuf_consume(@rbuf.size)
      end
    end

    def readline
      readuntil("\n").chop
    end

    private

    BUFSIZE = 1024 * 16

    def rbuf_fill
      tmp = @rbuf.empty? ? @rbuf : nil
      case rv = @io.read_nonblock(BUFSIZE, tmp, exception: false)
      when String
        return if rv.equal?(tmp)
        @rbuf << rv
        rv.clear
        return
      when :wait_readable
        (io = @io.to_io).wait_readable(@read_timeout) or raise Net::ReadTimeout.new(io)
        # continue looping
      when :wait_writable
        # OpenSSL::Buffering#read_nonblock may fail with IO::WaitWritable.
        # http://www.openssl.org/support/faq.html#PROG10
        (io = @io.to_io).wait_writable(@read_timeout) or raise Net::ReadTimeout.new(io)
        # continue looping
      when nil
        raise EOFError, 'end of file reached'
      end while true
    end

    def rbuf_consume(len)
      if len == @rbuf.size
        s = @rbuf
        @rbuf = ''.b
      else
        s = @rbuf.slice!(0, len)
      end
      @debug_output << %Q[-> #{s.dump}\n] if @debug_output
      s
    end

    #
    # Write
    #

    public

    def write(*strs)
      writing {
        write0(*strs)
      }
    end

    alias << write

    def writeline(str)
      writing {
        write0 str + "\r\n"
      }
    end

    private

    def writing
      @written_bytes = 0
      @debug_output << '<- ' if @debug_output
      yield
      @debug_output << "\n" if @debug_output
      bytes = @written_bytes
      @written_bytes = nil
      bytes
    end

    def write0(*strs)
      @debug_output << strs.map(&:dump).join if @debug_output
      orig_written_bytes = @written_bytes
      strs.each_with_index do |str, i|
        need_retry = true
        case len = @io.write_nonblock(str, exception: false)
        when Integer
          @written_bytes += len
          len -= str.bytesize
          if len == 0
            if strs.size == i+1
              return @written_bytes - orig_written_bytes
            else
              need_retry = false
              # next string
            end
          elsif len < 0
            str = str.byteslice(len, -len)
          else # len > 0
            need_retry = false
            # next string
          end
          # continue looping
        when :wait_writable
          (io = @io.to_io).wait_writable(@write_timeout) or raise Net::WriteTimeout.new(io)
          # continue looping
        end while need_retry
      end
    end

    #
    # Logging
    #

    private

    def LOG_off
      @save_debug_out = @debug_output
      @debug_output = nil
    end

    def LOG_on
      @debug_output = @save_debug_out
    end

    def LOG(msg)
      return unless @debug_output
      @debug_output << msg + "\n"
    end
  end


  class InternetMessageIO < BufferedIO   #:nodoc: internal use only
    def initialize(*)
      super
      @wbuf = nil
    end

    #
    # Read
    #

    def each_message_chunk
      LOG 'reading message...'
      LOG_off()
      read_bytes = 0
      while (line = readuntil("\r\n")) != ".\r\n"
        read_bytes += line.size
        yield line.delete_prefix('.')
      end
      LOG_on()
      LOG "read message (#{read_bytes} bytes)"
    end

    # *library private* (cannot handle 'break')
    def each_list_item
      while (str = readuntil("\r\n")) != ".\r\n"
        yield str.chop
      end
    end

    def write_message_0(src)
      prev = @written_bytes
      each_crlf_line(src) do |line|
        write0 dot_stuff(line)
      end
      @written_bytes - prev
    end

    #
    # Write
    #

    def write_message(src)
      LOG "writing message from #{src.class}"
      LOG_off()
      len = writing {
        using_each_crlf_line {
          write_message_0 src
        }
      }
      LOG_on()
      LOG "wrote #{len} bytes"
      len
    end

    def write_message_by_block(&block)
      LOG 'writing message from block'
      LOG_off()
      len = writing {
        using_each_crlf_line {
          begin
            block.call(WriteAdapter.new(self, :write_message_0))
          rescue LocalJumpError
            # allow `break' from writer block
          end
        }
      }
      LOG_on()
      LOG "wrote #{len} bytes"
      len
    end

    private

    def dot_stuff(s)
      s.sub(/\A\./, '..')
    end

    def using_each_crlf_line
      @wbuf = ''.b
      yield
      if not @wbuf.empty?   # unterminated last line
        write0 dot_stuff(@wbuf.chomp) + "\r\n"
      elsif @written_bytes == 0   # empty src
        write0 "\r\n"
      end
      write0 ".\r\n"
      @wbuf = nil
    end

    def each_crlf_line(src)
      buffer_filling(@wbuf, src) do
        while line = @wbuf.slice!(/\A[^\r\n]*(?:\n|\r(?:\n|(?!\z)))/)
          yield line.chomp("\n") + "\r\n"
        end
      end
    end

    def buffer_filling(buf, src)
      case src
      when String    # for speeding up.
        0.step(src.size - 1, 1024) do |i|
          buf << src[i, 1024]
          yield
        end
      when File    # for speeding up.
        while s = src.read(1024)
          buf << s
          yield
        end
      else    # generic reader
        src.each do |str|
          buf << str
          yield if buf.size > 1024
        end
        yield unless buf.empty?
      end
    end
  end


  #
  # The writer adapter class
  #
  class WriteAdapter
    def initialize(socket, method)
      @socket = socket
      @method_id = method
    end

    def inspect
      "#<#{self.class} socket=#{@socket.inspect}>"
    end

    def write(str)
      @socket.__send__(@method_id, str)
    end

    alias print write

    def <<(str)
      write str
      self
    end

    def puts(str = '')
      write str.chomp("\n") + "\n"
    end

    def printf(*args)
      write sprintf(*args)
    end
  end


  class ReadAdapter   #:nodoc: internal use only
    def initialize(block)
      @block = block
    end

    def inspect
      "#<#{self.class}>"
    end

    def <<(str)
      call_block(str, &@block) if @block
    end

    private

    # This method is needed because @block must be called by yield,
    # not Proc#call.  You can see difference when using `break' in
    # the block.
    def call_block(str)
      yield str
    end
  end


  module NetPrivate   #:nodoc: obsolete
    Socket = ::Net::InternetMessageIO
  end

end   # module Net
