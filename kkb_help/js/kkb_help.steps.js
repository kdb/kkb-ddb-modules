/**
 * @file
 * Step'by'step element behaviour.
 */

(function ($) {
  var updateAllToggle = function (items) {
    var not_shown = $('.js-step-item:not(.step-shown)', items);
    if (not_shown.length > 0) {
      $('.show-all', items.prev()).show();
      $('.hide-all', items.prev()).hide();
    }
    else {
      $('.show-all', items.prev()).hide();
      $('.hide-all', items.prev()).show();
    }
  };

  Drupal.behaviors.kkb_help_steps = {
    attach: function (context) {
      $('.js-step-items').once(function () {
        var items = $(this);

        $('.js-step-item', items).each(function () {
          var content = $('.js-step-content', this);
          var item = $(this);
          $('.js-step-title', this).after(' <span class="show">' + Drupal.t('Show') + '</span>');
          $('.js-step-title', this).after(' <span class="hide">' + Drupal.t('Hide') + '</span>');
          $('.js-step-header', this).click(function () {
            item.toggleClass('step-shown');
            updateAllToggle(items);
          });
        });

        var show_hide_all = $('<div class="show-hide-all"></div>');
        show_hide_all.append($(' <span class="show-all">' + Drupal.t('Show all') + '</span>').click(function () {
          $('.js-step-item', items).addClass('step-shown');
          updateAllToggle(items);
        }));
        show_hide_all.append($(' <span class="hide-all">' + Drupal.t('Hide all') + '</span>').click(function () {
          $('.js-step-item', items).removeClass('step-shown');
          updateAllToggle(items);
        }));

        $(this).before(show_hide_all);
        updateAllToggle(items);
      });
    }
  };
}(jQuery));

