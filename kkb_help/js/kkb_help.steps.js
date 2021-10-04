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

        var handleKeycode = function(event, callback) {
            // Return key
            if(event.keyCode === 13){
              callback();
            }
        };

        $('.js-step-item', items).each(function () {
          var content = $('.js-step-content', this);
          var item = $(this);
          $('.js-step-title', this).after(' <span class="show" tabindex="0">' + Drupal.t('Show') + '</span>');
          $('.js-step-title', this).after(' <span class="hide" tabindex="0">' + Drupal.t('Hide') + '</span>');
          $('.js-step-header', this)
            .click(function() {
              allToggle(item);
            })
            .on('keyup', function(event) {
              handleKeycode(event, function() {
                allToggle(item);
              });
            });
        });

        var show_hide_all = $('<div class="show-hide-all"></div>');

        show_hide_all.append($(' <span class="show-all" tabindex="0">' + Drupal.t('Show all') + '</span>')
          .on('click', stepShow)
          .on('keyup', function(event) {
            handleKeycode(event, stepShow);
          })
        );

        show_hide_all.append($(' <span class="hide-all" tabindex="0">' + Drupal.t('Hide all') + '</span>')
          .on('click', stepHide)
          .on('keyup', function(event) {
            handleKeycode(event, stepHide);
          })
        );

        $(this).before(show_hide_all);
        updateAllToggle(items);
      });
    }
  };
}(jQuery));

