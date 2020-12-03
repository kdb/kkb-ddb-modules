<?php
/**
 * @file
 * kkb_newsletter_paragraphs_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kkb_newsletter_paragraphs_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kkb_newsletter_paragraphs_feature_node_info() {
  $items = array(
    'newsletter_administration' => array(
      'name' => t('Newsletter administration'),
      'base' => 'node_content',
      'description' => t('Used for managing newsletter paragraphs'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function kkb_newsletter_paragraphs_feature_paragraphs_info() {
  $items = array(
    'kkb_newsletter' => array(
      'name' => 'Newsletter',
      'bundle' => 'kkb_newsletter',
      'locked' => '1',
    ),
  );
  return $items;
}
