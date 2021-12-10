/**
 * @file
 * Wayfinder integration.
 */

(function ($) {
  "use strict";

  function debounce (func, wait, immediate) {
    var timeout = void 0;
    var result = void 0;
    return function () {
      for (var _len = arguments.length, args = Array(_len), _key = 0; _key < _len; _key++) {
        args[_key] = arguments[_key];
      }

      var context = this;
      var later = function later() {
        timeout = null;
        if (!immediate) {
          result = func.apply(context, args);
        }
      };
      var callNow = immediate && !timeout;
      clearTimeout(timeout);
      timeout = setTimeout(later, wait);
      if (callNow) {
        result = func.apply(context, args);
      }
      return result;
    };
  }

  // Set elements width to the with of the slick-list container.
  function setElemWidth(elem) {
    elem.style.width = jQuery(elem).closest('.slick-list').width() + "px";
  }

  Drupal.behaviors.ding_wayfinder_slick = {
    attach: function (context) {
      if (Array.from(document.querySelectorAll('.slick-slide .ding-list-add-button')).length < 1) {
        return;
      }

      // The set of elements to resize
      const elemsToResize = new Set();

      // Find all buttons to each slick slide item.
      const targetNodes = Array.from(document.querySelectorAll('.ding-list-add-button')).filter(function(n) {
        return jQuery(n).closest('.slick-slide').length;
      });

      // Initially set the elements width
      targetNodes.forEach(function(elem) {
        const content = elem.querySelector('.content');
        setElemWidth(content);
      });

      // If an overlay is open, the content is added to the observed elements.
      var observer = new MutationObserver(function(mutations){
        mutations.forEach(function(mutation) {
          const content = mutation.target.querySelector('.content');
          if (Array.from(mutation.target.classList).includes('open-overlay')) {
            elemsToResize.add(content);
          } else {
            elemsToResize.delete(content);
          }
        });
      });

      // For each slide in a slick slide, we observe if the buttons class list changes.
      targetNodes.forEach(function(targetNode) {
        observer.observe(targetNode, {
          attributes: true,
          attributesFilter: ['class']
        });
      });

      // Whenever the viewport is resized, we set the size of the elements to resize.
      window.addEventListener('resize', debounce(function() {
        elemsToResize.forEach(setElemWidth);
      }, 250), {
        passive: true
      });
    }
  };
}(jQuery));
