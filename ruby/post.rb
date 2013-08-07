require 'uri'
require 'net/http'

#uri = URI("http://10.0.2.136/dispatch")
#req = Net::HTTP::Post.new(uri)
#req.set_form_data('start' => '2013-07-01', 'end' => '2013-07-31')

#res = Net::HTTP.start(uri.host,uri.port) do |http|
#    http.request(req)
#end
#
Net::HTTP.start('10.0.2.136', 80) {|http|
  response = http.post('/dispatch','querytype=subject&target=ruby')
}
