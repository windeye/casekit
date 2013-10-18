require 'redis-objects'
#class Redis
#end
include Redis::Objects
Redis.current = Redis.new(:host => '127.0.0.1', :port => 6379)

counter = Redis::Counter.new('counter_name')
counter.increment
counter.incr(3)

puts counter.value

@list = Redis::List.new('list_name')
@list << 'a'
@list << 'b'
@list.include? 'c'   # false
@list.values  # ['a','b']
@list << 'c'
