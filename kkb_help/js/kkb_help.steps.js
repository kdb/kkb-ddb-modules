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

  var updateAllToggle = function () {
    if ($(this).attr('aria-expanded') === 'false') {
      $('.js-step-item').addClass('step-shown');
      $('.js-help-button--text').each(function() {
        var $button = $(this);
        $button.attr('aria-expanded', true);
        $button.html(Drupal.t('Hide'));
      });
      $(this).html('<span>' + Drupal.t('Hide all') + '</span>');
      $(this).attr('aria-expanded', 'true');
    }
    else {
      $('.js-step-item').removeClass('step-shown');
      $('.js-help-button--text').each(function() {
        var $button = $(this);
        $button.attr('aria-expanded', false);
        $button.html(Drupal.t('Show'));
      });
      $(this).html('<span>' + Drupal.t('Show all') + '</span>');
      $(this).attr('aria-expanded', 'false');
    }
  };

  var toggleStepButton = function(context, item) {
    $(item).attr('aria-expanded', !($(item).attr('aria-expanded') === 'true'));

    // This is copied over from misc/collapse.js, since the button is
    // not hooked up to collapse.js.
    var fieldset = context.find('.collapsible').get(0);
    // Don't animate multiple times.
    if (!fieldset.animating) {
      fieldset.animating = true;
      // Call toggleFieldset in misc/collapse.js
      Drupal.toggleFieldset(fieldset);
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
          $('.fieldset-legend-prefix').attr('aria-hidden', true);

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

            // Insert the button instead of the title.
            $title.replaceWith($button);

            // After inserting the button, we need to find it in the document
            // and switch its expanded state. This is because after using replaceWith
            // you cannot add an on click handler directly on the button.
            $(document).on('click', '#ding-help-page-accordion__title--' + accordion_idx + '--' + idx, function() {
              toggleStepButton($this, this);
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
        items.attr('data-allow-multiple', '').attr('data-allow-toggle', '');

        $('.js-step-item', items).each(function (idx) {
          $('.js-step-content', this)
            .attr('id', 'step-content--' + idx)
            .attr('role', 'region')
            .attr('aria-labelledby', 'help-button--text--' + idx);

          var $item = $(this);
          $('.js-step-title', this).after(' <button id="help-button--text--' + idx + '" class="js-help-button--text help-button--text" aria-expanded="false" aria-controls="step-content--' + idx + '">' + Drupal.t('Show') + '</button>');
          $('.js-help-button--text', this).on('click', function() {
            var $button = $(this);
            $button.attr('aria-expanded', $button.attr('aria-expanded') === 'false');
            $button.html($button.attr('aria-expanded') === 'false' ? Drupal.t('Show') : Drupal.t('Hide'));
            $item.toggleClass('step-shown');
            $button.select();
          });
        });

        var show_hide_all = $('<div class="show-hide-all"></div>');

        show_hide_all.append($(' <button class="help-button--text show-hide-all" aria-expanded="false"><span>' + Drupal.t('Show all') + '</span></button>')
          .attr('aria-controls', 'test')
          .on('click', updateAllToggle));

        $(this).before(show_hide_all);
      });
    }
  };
}(jQuery));

