require 'eventmachine'

EM.run do
  n = 0
  work = proc do
    if n < 100
      n += 1
      puts n
      EM.next_tick(work)
    else
      EM.stop()
    end
  end

  EM.next_tick(work)
end
