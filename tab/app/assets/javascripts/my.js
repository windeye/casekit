$(document).reday(funtion() {
    $size = $('#favourite')
    $size.click(function() {
      var $this = $(this);
      window.animateAddToBag($this, function() {
      });
    });
});
