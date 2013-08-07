require 'eventmachine'

EM.run do
  p = EM::PeriodicTimer.new(1) do
    puts 'Ticks 1'
  end

  EM::Timer.new(5) do
    puts 'BOOM'
    p.cancel
  end

  EM::Timer.new(8) do
    puts 'end everything!'
  end

end
