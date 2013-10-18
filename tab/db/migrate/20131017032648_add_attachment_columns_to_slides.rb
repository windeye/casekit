class AddAttachmentColumnsToSlides < ActiveRecord::Migration
  def self.up
    add_attachment :slides, :avatar
  end

  def self.down
    remove_attachment :slides, :avatar
  end
end
