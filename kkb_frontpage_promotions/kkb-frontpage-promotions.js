(function($) {
  "use strict";

  $(function () {
    var $topbar;

    if (!$('body').hasClass('has-kkb-promotion')) {
      return;
    }

    $(window).bind('scroll', function (evt) {
      $('body').toggleClass('kkb-promotion-scroll-line', $(window).scrollTop() < 455);
    }).trigger('scroll');
  });

}(jQuery));
