json.array!(@cates) do |cate|
  json.extract! cate, 
  json.url cate_url(cate, format: :json)
end
