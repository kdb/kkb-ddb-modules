<?php
/**
 * @file
 * kkb_newsletter_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kkb_newsletter_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function kkb_newsletter_paragraphs_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function kkb_newsletter_paragraphs_image_default_styles() {
  $styles = array();

  // Exported image style: newsletter_landscape.
  $styles['newsletter_landscape'] = array(
    'label' => 'Newsletter landscape',
    'effects' => array(
      4 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 504,
          'height' => 162,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function kkb_newsletter_paragraphs_node_info() {
  $items = array(
    'newsletter_administration' => array(
      'name' => t('Newsletter administration'),
      'base' => 'node_content',
      'description' => t('Used for managing newsletter paragraphs'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function kkb_newsletter_paragraphs_paragraphs_info() {
  $items = array(
    'kkb_newsletter' => array(
      'name' => 'Newsletter template',
      'bundle' => 'kkb_newsletter',
      'locked' => '1',
    ),
    'kkb_newsletter_reference' => array(
      'name' => 'Newsletter',
      'bundle' => 'kkb_newsletter_reference',
      'locked' => '1',
    ),
  );
  return $items;
}
