<?php
/**
 * @file
 * kkb_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kkb_library_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
