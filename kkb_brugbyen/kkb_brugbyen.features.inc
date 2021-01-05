<?php
/**
 * @file
 * kkb_brugbyen.features.inc
 */

/**
 * Implements hook_field_default_field_bases_alter().
 */
function kkb_brugbyen_field_default_field_bases_alter(&$data) {
  if (isset($data['field_ding_event_category'])) {
    $data['field_ding_event_category']['cardinality'] = -1; /* WAS: 1 */
    $data['field_ding_event_category']['settings']['options_list_callback'] = 'i18n_taxonomy_allowed_values'; /* WAS: '' */
  }
}
