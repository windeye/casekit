class Slide < ActiveRecord::Base
  has_attached_file :avatar,:url => "/uploads/:class/:attachment/:style/:filename",
                    :styles => { :images => { :params => "-r88",:format => "png" } },
                    :processors => [:pdf_picize]

  before_create :store_meta_info

  def store_meta_info
    #@current_format = File.extname(avatar_file_name)
    #@basename       = File.basename(avatar_file_name, @current_format)
    p = self.avatar.path
    reader = PDF::Reader.new(p)
    self.page_count = reader.page_count
    self.file_id =  Digest::SHA1.hexdigest(avatar_file_name)
    self.avatar.instance_write(:file_name, "#{self.file_id}_#{avatar_file_name}")
    self.file_id = p
  end
end
