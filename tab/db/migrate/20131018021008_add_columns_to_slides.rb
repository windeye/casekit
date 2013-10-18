class AddColumnsToSlides < ActiveRecord::Migration
  def change
     add_column :slides, :page_count, :integer 
     add_column :slides, :file_id, :string
  end
end
