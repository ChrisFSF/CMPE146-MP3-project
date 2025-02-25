# frozen_string_literal: true

module Bundler
  class FeatureFlag
    def self.settings_flag(flag, &default)
      unless Bundler::Settings::BOOL_KEYS.include?(flag.to_s)
        raise "Cannot use `#{flag}` as a settings feature flag since it isn't a bool key"
      end

      settings_method("#{flag}?", flag, &default)
    end
    private_class_method :settings_flag

    def self.settings_option(key, &default)
      settings_method(key, key, &default)
    end
    private_class_method :settings_option

    def self.settings_method(name, key, &default)
      define_method(name) do
        value = Bundler.settings[key]
        value = instance_eval(&default) if value.nil? && !default.nil?
        value
      end
    end
    private_class_method :settings_method

    (1..10).each {|v| define_method("bundler_#{v}_mode?") { major_version >= v } }

    settings_flag(:allow_bundler_dependency_conflicts) { bundler_2_mode? }
    settings_flag(:allow_offline_install) { bundler_2_mode? }
    settings_flag(:auto_clean_without_path) { bundler_2_mode? }
    settings_flag(:auto_config_jobs) { bundler_2_mode? }
    settings_flag(:cache_all) { bundler_2_mode? }
    settings_flag(:cache_command_is_package) { bundler_2_mode? }
    settings_flag(:console_command) { !bundler_2_mode? }
    settings_flag(:default_install_uses_path) { bundler_2_mode? }
    settings_flag(:deployment_means_frozen) { bundler_2_mode? }
    settings_flag(:disable_multisource) { bundler_2_mode? }
    settings_flag(:error_on_stderr) { bundler_2_mode? }
    settings_flag(:forget_cli_options) { bundler_2_mode? }
    settings_flag(:global_path_appends_ruby_scope) { bundler_2_mode? }
    settings_flag(:global_gem_cache) { bundler_2_mode? }
    settings_flag(:init_gems_rb) { bundler_2_mode? }
    settings_flag(:list_command) { bundler_2_mode? }
    settings_flag(:lockfile_uses_separate_rubygems_sources) { bundler_2_mode? }
    settings_flag(:only_update_to_newer_versions) { bundler_2_mode? }
    settings_flag(:path_relative_to_cwd) { bundler_2_mode? }
    settings_flag(:plugins) { @bundler_version >= Gem::Version.new("1.14") }
    settings_flag(:prefer_gems_rb) { bundler_2_mode? }
    settings_flag(:print_only_version_number) { bundler_2_mode? }
    settings_flag(:setup_makes_kernel_gem_public) { !bundler_2_mode? }
    settings_flag(:skip_default_git_sources) { bundler_2_mode? }
    settings_flag(:specific_platform) { bundler_2_mode? }
    settings_flag(:suppress_install_using_messages) { bundler_2_mode? }
    settings_flag(:unlock_source_unlocks_spec) { !bundler_2_mode? }
    settings_flag(:update_requires_all_flag) { bundler_2_mode? }
    settings_flag(:use_gem_version_promoter_for_major_updates) { bundler_2_mode? }
    settings_flag(:viz_command) { !bundler_2_mode? }

    settings_option(:default_cli_command) { bundler_2_mode? ? :cli_help : :install }

    settings_method(:github_https?, "github.https") { bundler_2_mode? }

    def initialize(bundler_version)
      @bundler_version = Gem::Version.create(bundler_version)
    end

    def major_version
      @bundler_version.segments.first
    end
    private :major_version
  end
end
