require 'pdf-reader'
#reader = PDF::Reader.new("/root/pdfs/Redis_Cluster.pdf")
begin
  reader = PDF::Reader.new("/root/pdfs/CPU.pptx")

  puts reader.pdf_version
  puts reader.metadata
  puts reader.page_count
  puts reader.info
rescue
  raise PaperclipError, "There was an error converting to pic"
end
