<?php
/**
 * @file
 * kdb_social_content.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function kdb_social_content_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-ding_event-field_marketing_category'.
  $field_instances['node-ding_event-field_marketing_category'] = array(
    'bundle' => 'ding_event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Used for filtering events on https:://brugbyen.nu',
    'display' => array(
      'alternative_layout_full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 16,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser_highlight' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser_no_overlay' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_marketing_category',
    'label' => 'Marketing category',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'match_operator' => 'CONTAINS',
      ),
      'type' => 'options_select',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-ding_event-field_theme_category'.
  $field_instances['node-ding_event-field_theme_category'] = array(
    'bundle' => 'ding_event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'These tags makes it possible to expose the event on theme pages and filtered views on https://brugbyen.nu',
    'display' => array(
      'alternative_layout_full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 15,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser_highlight' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser_no_overlay' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_theme_category',
    'label' => 'Theme category',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'match_operator' => 'CONTAINS',
      ),
      'type' => 'options_select',
      'weight' => 12,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Marketing category');
  t('Theme category');
  t('These tags makes it possible to expose the event on theme pages and filtered views on https://brugbyen.nu');
  t('Used for filtering events on https:://brugbyen.nu');

  return $field_instances;
}
