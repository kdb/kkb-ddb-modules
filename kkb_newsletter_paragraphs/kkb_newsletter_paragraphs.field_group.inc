<?php
/**
 * @file
 * kkb_newsletter_paragraphs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kkb_newsletter_paragraphs_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ding_event_other|node|ding_event|form';
  $field_group->group_name = 'group_ding_event_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ding_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '6',
    'children' => array(
      0 => 'field_event_newsletter',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ding-event-other field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_ding_event_other|node|ding_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|node|ding_event|default';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ding_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '3',
    'children' => array(
      0 => 'field_ding_event_body',
      1 => 'field_ding_event_date',
      2 => 'field_ding_event_files',
      3 => 'field_ding_event_lead',
      4 => 'field_ding_event_tags',
      5 => 'webform',
      6 => 'field_event_newsletter',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_right|node|ding_event|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Other');

  return $field_groups;
}
