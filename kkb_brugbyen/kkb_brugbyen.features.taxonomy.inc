<?php
/**
 * @file
 * kkb_brugbyen.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kkb_brugbyen_taxonomy_default_vocabularies() {
  return array(
    'marketing_category' => array(
      'name' => 'Brugbyen.nu marketing category',
      'machine_name' => 'marketing_category',
      'description' => 'This taxonomy is used for filtering of events on https://brugbyen.nu',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'theme_category' => array(
      'name' => 'Brugbyen.nu theme category',
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
