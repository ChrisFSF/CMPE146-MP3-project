:""||{ ""=> %q<-*- ruby -*-
@"%~dp0ruby" -x "%~f0" %*
@exit /b %ERRORLEVEL%
};{#
bindir="${0%/*}" #
exec "$bindir/ruby" "-x" "$0" "$@" #
>,
}
#!/usr/bin/env ruby
#--
# Copyright 2006 by Chad Fowler, Rich Kilmer, Jim Weirich and others.
# All rights reserved.
# See LICENSE.txt for permissions.
#++

require 'rubygems'
require 'rubygems/gem_runner'
require 'rubygems/exceptions'

required_version = Gem::Requirement.new ">= 1.8.7"

unless required_version.satisfied_by? Gem.ruby_version then
  abort "Expected Ruby Version #{required_version}, is #{Gem.ruby_version}"
end

args = ARGV.clone

begin
  Gem::GemRunner.new.run args
rescue Gem::SystemExitException => e
  exit e.exit_code
end

