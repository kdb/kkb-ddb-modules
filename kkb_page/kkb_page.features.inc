<?php
/**
 * @file
 * kkb_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kkb_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_field_bases_alter().
 */
function kkb_page_field_default_field_bases_alter(&$data) {
  if (isset($data['field_ding_page_files'])) {
    $data['field_ding_page_files']['settings']['display_default'] = 1; /* WAS: 0 */
    $data['field_ding_page_files']['settings']['display_field'] = 1; /* WAS: 0 */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function kkb_page_field_default_field_instances_alter(&$data) {
  if (isset($data['node-ding_page-field_ding_page_list_image'])) {
    $data['node-ding_page-field_ding_page_list_image']['required'] = 1; /* WAS: 0 */
  }
}
