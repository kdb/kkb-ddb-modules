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

            // If the "special exposed event" checkbox is not checked,
            // we need to reset the date group fields to avoid validation errors.
            // We only do this on submit, because we want to keep the values if the
            // user unchecks and checks the "special exposed event" checkbox.
            var submit = document.querySelector('#edit-submit');
            submit.addEventListener('click', function() {
                if (!checkbox.checked) {
                    var inputs = Array.from(dates.querySelectorAll('input[type=text]'));
                    inputs.map(function(input) {
                        input.value = '';
                    });
                }
            });
        }
    };
})();
