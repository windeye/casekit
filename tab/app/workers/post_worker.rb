class PostWorker
  include Sidekiq::Worker

  def perform(post_id)
    post = Post.find_by_id(post_id)
    post.content = "yes,add by post worker backend!" 
    post.save!
  end
end
