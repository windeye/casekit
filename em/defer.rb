require 'eventmachine'

EM.run do
  op = proc do
    3+3
  end

  callback = proc do |count|
    puts "3+3 = #{count}"
    EM.stop()
  end
  EM.defer(op,callback)
end
