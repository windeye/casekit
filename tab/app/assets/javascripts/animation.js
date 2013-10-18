$(function() {
  // preload images to prevent them from appearing mid-animation

  /* Performs a bounce animation on the given element.
   *
   * Arguments:
   * element -- the element to bounce
   */
  function animateBounce(element) {
    /* Ends the bounce. */
    function endBounceAnimation() {
      element.removeClass('bounce');
    }

    element.one('webkitAnimationEnd', endBounceAnimation);
    element.one('animationend', endBounceAnimation);

    element.addClass('bounce');
  }

  /* Performs an add to bag animation.
   *
   * Arguments:
   * startButton -- the add to bag button to start the animation from
   * callback -- the callback to call once finished
   */
  window.animateAddToBag = function(startButton, callback) {
    var endButton = $('#bag');
    var animationDuration = 700;

    // animation attributes at the start, middle, and end
    var start = {
      'scale': 1.0,
      'x': startButton.offset().left + startButton.outerWidth() / 2,
      'y': startButton.offset().top + startButton.outerHeight() / 2
    };

    var end = {
      'scale': 0.0,
      'x': endButton.offset().left + endButton.outerWidth() / 2,
      'y': endButton.offset().top + endButton.outerHeight() / 2
    };

    var mid = {
      'scale': 4.0,
      'x': Math.min(start.x, end.x) + 50,
      'y': Math.min(start.y, end.y) + 50
    };

    init();
    animate();

    // animation helper
    $(helper).css({
      '-webkit-transform': 'translate(' + start.x + 'px, ' + start.y + 'px)',
      'transform': 'translate(' + start.x + 'px, ' + start.y + 'px)',
    }).show();

    /* Initializes the TWEEN animation. */
    function init() {
      var tween = new TWEEN.Tween(start);
      tween.to({
        'x': [mid.x, end.x],
        'y': [mid.y, end.y],
        'scale': [mid.scale, end.scale]
      }, animationDuration);

      tween.easing(TWEEN.Easing.Sinusoidal.Out);
      tween.onUpdate(function() {
        helper.style.webkitTransform = 'translate(' + this.x + 'px, ' +
          this.y + 'px)';
        shirt.style.webkitTransform = 'scale(' + this.scale + ')';

        helper.style.transform = 'translate(' + this.x + 'px, ' +
          this.y + 'px)';
        shirt.style.transform = 'scale(' + this.scale + ')';
      });

      tween.interpolation(TWEEN.Interpolation.Bezier);
      tween.onComplete(function() {
        $(helper).hide();
        animateBounce(endButton);

        if (callback) {
          setTimeout(callback, 400);
        }
      });

      tween.start();
    }

    /* Performs the animation. */
    function animate() {
      window.requestAnimationFrame(animate);
      TWEEN.update();
    }
  };
});
