/**
 * @file
 * Step'by'step element behaviour.
 */

(function ($) {
  'use strict';

  // Since .fieldset-title is appended to the accordion by misc/collapse.js
  // we need to wait for it in the dom, before doing anything else.
  var waitForFieldsetTitle = function($item, cb) {
    // If its already there, return early.
    if ($item.find('.fieldset-title').length) {
      return cb();
    }

    // Wait for the fieldset-title to be inserted, then disable the observer
    // and call the callback.
    let observer = new MutationObserver((mutations) => {
      mutations.forEach((mutation) => {
        if (!mutation.addedNodes) {
          return;
        }

        for (let i = 0; i < mutation.addedNodes.length; i++) {
          let node = mutation.addedNodes[i];
          if (node.classList && node.classList.contains('fieldset-title')) {
            observer.disconnect();
            return cb();
          }
        }
      });
    });

    observer.observe($item.get(0), {
      childList: true
      , subtree: true
      , attributes: false
      , characterData: false
    });
  };

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
    attach: function () {
      $('.paragraphs-item-ding-help-page-accordion').once(function(accordion_idx) {
        var $this = $(this);
        // These are used to tell the accordion what kind of behaviour it can have.
        $this.attr('data-allow-toggle');
        $this.attr('data-allow-multiple');

        waitForFieldsetTitle($this, function() {

          $this.find('.fieldset-wrapper').each(function(idx, wrapper) {
            var $wrapper = $(wrapper);
            $wrapper.attr('id', 'fieldset-wrapper--' + accordion_idx + '--'  + idx);
            $wrapper.attr('aria-labelledby', 'ding-help-page-accordion__title--' + accordion_idx + '--' + idx);
            $wrapper.attr('role', 'region');
          });

          // Make the accordion title accessible by changing it to an aria enabled button.
          $this.find('.ding-help-page-accordion__title').each(function(idx, title) {
            // Copy the title classes over to a new button element.
            var $title = $(title);
            var classes = $title.attr('class');
            var $button = $('<button class="' + classes + '">' + $title.html() + '</button>');

            // Make it compliant with wcag accordions.
            $button.attr('id', 'ding-help-page-accordion__title--' + accordion_idx + '--'  + idx);
            $button.attr('aria-controls', 'fieldset-wrapper--' + accordion_idx + '--'  + idx);
            $button.attr('aria-expanded', false);
            $button.attr('aria-role', 'button');

            // Insert the button instead of the title.
            $title.replaceWith($button);

            // After inserting the button, we need to find it in the document
            // and switch its expanded state. This is because after using replaceWith
            // you cannot add an on click handler directly on the button.
            $(document).on('click', '#ding-help-page-accordion__title--' + accordion_idx + '--' + idx, function() {
              $(this).attr('aria-expanded', $(this).attr('aria-expanded') === 'false');

              // This is copied over from misc/collapse.js, since the button is
              // not hooked up to collapse.js.
              var fieldset = $this.find('.collapsible').get(0);
              // Don't animate multiple times.
              if (!fieldset.animating) {
                fieldset.animating = true;
                // Call toggleFieldset in misc/collapse.js
                Drupal.toggleFieldset(fieldset);
              }
            });
          });

          // fieldset-title should be changed from an 'a' tag to an 'h2' tag.
          // We do this because we do not want the button to be wrapped in an 'a',
          // this would cause screen readers to see the button as both a link
          // and a button.
          $this.find('.fieldset-title').each(function(idx, title) {
            $(title).replaceWith('<h2 class="fieldset-title">' + $(title).html() + '</h2>');
          });
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
          $('.js-step-title', this).after(' <button class="help-button--text">' + Drupal.t('Show') + '</button>');
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

