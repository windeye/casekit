

def run(cmd, arguments = "", interpolation_values = {}, local_options = {}) 
  command_path = options[:command_path]
  Cocaine::CommandLine.path = [Cocaine::CommandLine.path, command_path].flatten.compact.uniq
  if logging? && (options[:log_command] || local_options[:log_command])
    local_options = local_options.merge(:logger => logger)
  end                                                                                                                             
  Cocaine::CommandLine.new(cmd, arguments, local_options).run(interpolation_values)
end 
