class Slide < ActiveRecord::Base
  has_attached_file :avatar, 
                    :styles => { :images => { :params => "-r88",:format => "png" } },
                    :processors => [:pdf_picize]
end
