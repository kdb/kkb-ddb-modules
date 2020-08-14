<?php
/**
 * @file
 * kdb_social_content.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kdb_social_content_taxonomy_default_vocabularies() {
  return array(
    'marketing_category' => array(
      'name' => 'Marketing Category',
      'machine_name' => 'marketing_category',
      'description' => 'This taxonomy is used for filtering of events on https://brugbyen.nu',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'theme_category' => array(
      'name' => 'Theme category',
      'machine_name' => 'theme_category',
      'description' => 'These terms make it possible to expose your event in themes and filters on https://brugbyen.nu',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
