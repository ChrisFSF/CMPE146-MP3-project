# frozen_string_literal: false
#
#   irb/ext/cb.rb -
#   	$Release Version: 0.9.6$
#   	$Revision: 53141 $
#   	by Keiju ISHITSUKA(keiju@ruby-lang.org)
#
# --
#
#
#

module IRB # :nodoc:
  class Context

    # Inherited from +TOPLEVEL_BINDING+.
    def home_workspace
      if defined? @home_workspace
        @home_workspace
      else
        @home_workspace = @workspace
      end
    end

    # Changes the current workspace to given object or binding.
    #
    # If the optional argument is omitted, the workspace will be
    # #home_workspace which is inherited from +TOPLEVEL_BINDING+ or the main
    # object, <code>IRB.conf[:MAIN_CONTEXT]</code> when irb was initialized.
    #
    # See IRB::WorkSpace.new for more information.
    def change_workspace(*_main)
      if _main.empty?
        @workspace = home_workspace
        return main
      end

      @workspace = WorkSpace.new(_main[0])

      if !(class<<main;ancestors;end).include?(ExtendCommandBundle)
        main.extend ExtendCommandBundle
      end
    end
  end
end

