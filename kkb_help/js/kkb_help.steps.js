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
      $('.collapsible .fieldset-title').once(function() {
        this.setAttribute('aria-expanded', false);
        $(this).on('click', function() {
          this.setAttribute('aria-expandend', !this.getAttribute('aria-expandend'));
        });
      });

      $('.js-step-items').once(function () {
        var items = $(this);

        var allToggle = function (item) {
          item.toggleClass('step-shown');
          updateAllToggle(items);
        };

        var stepShow = function () {
          $('.js-step-item', items).addClass('step-shown');
          updateAllToggle(items);
        };

        var stepHide = function () {
          $('.js-step-item', items).removeClass('step-shown');
          updateAllToggle(items);
        };

        $('.js-step-item', items).each(function () {
          var content = $('.js-step-content', this);
          var item = $(this);
          $('.js-step-title', this).after(' <button class="help-button--text show">' + Drupal.t('Show') + '</button>');
          $('.js-step-title', this).after(' <button class="help-button--text hide">' + Drupal.t('Hide') + '</button>');
          $('.js-step-header', this).click(function() {
              allToggle(item);
            });
        });

        var show_hide_all = $('<div class="show-hide-all"></div>');

        show_hide_all.append($(' <button class="help-button--text show-all">' + Drupal.t('Show all') + '</button>').on('click', stepShow));

        show_hide_all.append($(' <button class="help-button--text hide-all">' + Drupal.t('Hide all') + '</button>').on('click', stepHide));

        $(this).before(show_hide_all);
        updateAllToggle(items);
      });
    }
  };
}(jQuery));

