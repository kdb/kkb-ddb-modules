<?php
/**
 * @file
 * kkb_e_rsurser.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function kkb_e_rsurser_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:e-resurser
  $menu_links['main-menu:e-resurser'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'e-resurser',
    'router_path' => 'e-resurser',
    'link_title' => 'E-resurser',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('E-resurser');


  return $menu_links;
}
