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

/**
 * Implements hook_strongarm_alter().
 */
function kkb_event_strongarm_alter(&$data) {
  if (isset($data['comment_ding_event'])) {
    $data['comment_ding_event']->value = 2; /* WAS: 1 */
  }
}
