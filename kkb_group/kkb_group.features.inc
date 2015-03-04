<?php
/**
 * @file
 * kkb_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kkb_group_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
