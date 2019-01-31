<?php
/**
 * @file
 * kkb_help.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kkb_help_taxonomy_default_vocabularies() {
  return array(
    'help_category' => array(
      'name' => 'Help Category',
      'machine_name' => 'help_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
  );
}
