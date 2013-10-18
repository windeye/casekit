class Post < ActiveRecord::Base
  include Redis::Objects
  after_create :adjust_score

  class << self
    def rankings
      Redis::SortedSet.new("post_ranking")
    end
  end
  
  def adjust_score
    Post.rankings.incr(id,3)
  end
end
