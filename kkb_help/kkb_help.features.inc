<?php
/**
 * @file
 * kkb_help.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kkb_help_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function kkb_help_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function kkb_help_node_info() {
  $items = array(
    'ding_help_page' => array(
      'name' => t('Hjælpeside'),
      'base' => 'node_content',
      'description' => t('Indholdstype for hjælpesider.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
