<?php
/**
 * @file
 * kkb_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kkb_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}