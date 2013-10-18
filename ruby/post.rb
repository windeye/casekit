require 'uri'
require 'net/http'
require 'digest/md5'

def post_to_ade(query)
  Net::HTTP.start('10.0.2.136', 80) {|http|
    res = http.post('/dispatch',query)
    puts "POST result:"
    puts res.body
  }
end


def get_from_ade(query)
  uri = URI('http://10.0.2.136/dispatch?'+query)
  res = Net::HTTP.get_response(uri)
  puts "GET result:"
  puts res.body
end



t = 1000 * Time.now.to_i
ts = t.to_s
sign = Digest::MD5.hexdigest("appid=12plat=mogotimestamp=" + ts + "0123456789ABCDEF")
query = "plat=mogo&appid=12&timestamp=" + ts + "&sign=" + sign

get_from_ade(query)
post_to_ade(query)
