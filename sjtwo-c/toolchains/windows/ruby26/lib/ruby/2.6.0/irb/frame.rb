# frozen_string_literal: false
#
#   frame.rb -
#   	$Release Version: 0.9$
#   	$Revision: 53141 $
#   	by Keiju ISHITSUKA(Nihon Rational Software Co.,Ltd)
#
# --
#
#
#

require "e2mmap"

module IRB
  class Frame
    extend Exception2MessageMapper
    def_exception :FrameOverflow, "frame overflow"
    def_exception :FrameUnderflow, "frame underflow"

    # Default number of stack frames
    INIT_STACK_TIMES = 3
    # Default number of frames offset
    CALL_STACK_OFFSET = 3

    # Creates a new stack frame
    def initialize
      @frames = [TOPLEVEL_BINDING] * INIT_STACK_TIMES
    end

    # Used by Kernel#set_trace_func to register each event in the call stack
    def trace_func(event, file, line, id, binding)
      case event
      when 'call', 'class'
        @frames.push binding
      when 'return', 'end'
        @frames.pop
      end
    end

    # Returns the +n+ number of frames on the call stack from the last frame
    # initialized.
    #
    # Raises FrameUnderflow if there are no frames in the given stack range.
    def top(n = 0)
      bind = @frames[-(n + CALL_STACK_OFFSET)]
      Fail FrameUnderflow unless bind
      bind
    end

    # Returns the +n+ number of frames on the call stack from the first frame
    # initialized.
    #
    # Raises FrameOverflow if there are no frames in the given stack range.
    def bottom(n = 0)
      bind = @frames[n]
      Fail FrameOverflow unless bind
      bind
    end

    # Convenience method for Frame#bottom
    def Frame.bottom(n = 0)
      @backtrace.bottom(n)
    end

    # Convenience method for Frame#top
    def Frame.top(n = 0)
      @backtrace.top(n)
    end

    # Returns the binding context of the caller from the last frame initialized
    def Frame.sender
      eval "self", @backtrace.top
    end

    @backtrace = Frame.new
    set_trace_func proc{|event, file, line, id, binding, klass|
      @backtrace.trace_func(event, file, line, id, binding)
    }
  end
end
