# frozen_string_literal: false
#
#   help.rb - helper using ri
#   	$Release Version: 0.9.6$
#   	$Revision: 65506 $
#
# --
#
#
#

require 'rdoc/ri/driver'

require_relative "nop"

# :stopdoc:
module IRB
  module ExtendCommand
    class Help < Nop
      begin
        Ri = RDoc::RI::Driver.new
      rescue SystemExit
      else
        def execute(*names)
          if names.empty?
            Ri.interactive
            return
          end
          names.each do |name|
            begin
              Ri.display_name(name.to_s)
            rescue RDoc::RI::Error
              puts $!.message
            end
          end
          nil
        end
      end
    end
  end
end
# :startdoc:
