(function() {
    Drupal.behaviors.kultunautFeedForm = {
        attach: function () {
            // The checkbox controls wether we show or hide the dates group.
            var checkbox = document.querySelector('#edit-field-special-exposed-event-und');
            var dates = document.querySelector('#edit-field-exposed-dates');
            dates.style.display = checkbox.checked ? 'inherit' : 'none';
            checkbox.addEventListener( 'change', function() {
                dates.style.display = this.checked ? 'inherit' : 'none';
            });

            // Because we move this in ding_kultunaut_feed_form_alter,
            // we need to set its state. But we do not need to monitor it,
            // like our custom handler above.
            var showToDateCheckbox = document.querySelector('#edit-field-exposed-dates-und-0-show-todate');
            var endDates = document.querySelector('.form-item-field-exposed-dates-und-0-value2');
            endDates.style.display = showToDateCheckbox.checked ? 'inherit' : 'none';
        }
    };
})();
