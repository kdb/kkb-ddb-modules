(function() {
    "use strict";

    Drupal.behaviors.ding_kultunaut_form = {
        attach: function () {
            var checked = document.querySelector('#edit-field-special-exposed-event-und').checked;
            document.querySelector('#edit-field-exposed-dates').style.display = checked ? 'block' : 'none';
        }
    };
})();