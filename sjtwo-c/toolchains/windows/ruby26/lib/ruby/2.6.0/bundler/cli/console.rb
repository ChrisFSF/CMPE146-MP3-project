# frozen_string_literal: true

module Bundler
  class CLI::Console
    attr_reader :options, :group
    def initialize(options, group)
      @options = options
      @group = group
    end

    def run
      Bundler::SharedHelpers.major_deprecation 2, "bundle console will be replaced " \
                           "by `bin/console` generated by `bundle gem <name>`"

      group ? Bundler.require(:default, *(group.split.map!(&:to_sym))) : Bundler.require
      ARGV.clear

      console = get_console(Bundler.settings[:console] || "irb")
      console.start
    end

    def get_console(name)
      require name
      get_constant(name)
    rescue LoadError
      Bundler.ui.error "Couldn't load console #{name}, falling back to irb"
      require "irb"
      get_constant("irb")
    end

    def get_constant(name)
      const_name = {
        "pry"  => :Pry,
        "ripl" => :Ripl,
        "irb"  => :IRB,
      }[name]
      Object.const_get(const_name)
    rescue NameError
      Bundler.ui.error "Could not find constant #{const_name}"
      exit 1
    end
  end
end
