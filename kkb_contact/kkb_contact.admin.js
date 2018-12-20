/**
 * @file
 * JavaScript for the settings form.
 */

(function ($) {

  /**
   * Handle the concept of a fixed number of slots.
   *
   * This behavior is dependent on the tableDrag behavior, since it uses the
   * objects initialized in that behavior to update the row.
   */
  Drupal.behaviors.shortcutDrag = {
    attach: function (context, settings) {
      if (Drupal.tableDrag) {
        var table = $('table#kkb-contact-settings-admin-sort'),
            tableDrag = Drupal.tableDrag['kkb-contact-settings-admin-sort'];

        // Add a handler so when a row is dropped, update fields dropped into new regions.
        tableDrag.onDrop = function () {
          tableDrag.rowStatusChange(this.rowObject);
          return true;
        };

        tableDrag.rowStatusChange = function (rowObject) {
          var statusRow = $(rowObject.element).prevAll('tr.js-kkb-contact-settings-status').get(0);
          console.dir(statusRow);
          var statusName = statusRow.className.replace(/([^ ]+[ ]+)*js-kkb-contact-settings-status-([^ ]+)([ ]+[^ ]+)*/, '$2');
          var statusField = $('select.kkb-contact-settings-element-status', rowObject.element);
          statusField.val(statusName);
        };
      }
    }
  };
})(jQuery);
