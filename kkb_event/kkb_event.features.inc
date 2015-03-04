<?php
/**
 * @file
 * kkb_event.features.inc
 */

/**
 * Implements hook_field_default_field_bases_alter().
 */
function kkb_event_field_default_field_bases_alter(&$data) {
  if (isset($data['field_ding_event_files'])) {
    $data['field_ding_event_files']['settings']['display_default'] = 1; /* WAS: 0 */
    $data['field_ding_event_files']['settings']['display_field'] = 1; /* WAS: 0 */
  }
}
