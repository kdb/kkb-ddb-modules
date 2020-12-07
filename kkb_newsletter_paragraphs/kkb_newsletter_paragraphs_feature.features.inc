<?php
/**
 * @file
 * kkb_newsletter_paragraphs_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kkb_newsletter_paragraphs_feature_ctools_plugin_api($module = NULL, $api = NULL) {
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
function kkb_newsletter_paragraphs_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_field_default_field_bases_alter().
 */
function kkb_newsletter_paragraphs_feature_field_default_field_bases_alter(&$data) {
  if (isset($data['field_ding_page_paragraphs'])) {
    unset($data['field_ding_page_paragraphs']['foreign keys']);
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function kkb_newsletter_paragraphs_feature_field_default_field_instances_alter(&$data) {
  if (isset($data['node-ding_news-field_ding_news_paragraphs'])) {
    $data['node-ding_news-field_ding_news_paragraphs']['display']['teaser_no_overlay'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['allowed_bundles']['ding_help_front_box'] = 1; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['allowed_bundles']['ding_help_page_accordion'] = 1; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['allowed_bundles']['ding_help_page_body'] = 1; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['allowed_bundles']['ding_help_page_cta'] = 1; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['allowed_bundles']['ding_help_page_step'] = 1; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['allowed_bundles']['ding_help_page_step_by_step'] = 1; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['allowed_bundles']['kkb_newsletter'] = 1; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['allowed_bundles']['kkb_newsletter_reference'] = 'kkb_newsletter_reference'; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['bundle_weights']['ding_help_front_box'] = 13; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['bundle_weights']['ding_help_page_accordion'] = 14; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['bundle_weights']['ding_help_page_body'] = 15; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['bundle_weights']['ding_help_page_cta'] = 16; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['bundle_weights']['ding_help_page_step'] = 17; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['bundle_weights']['ding_help_page_step_by_step'] = 18; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['bundle_weights']['kkb_newsletter'] = 26; /* WAS: '' */
    $data['node-ding_news-field_ding_news_paragraphs']['settings']['bundle_weights']['kkb_newsletter_reference'] = 27; /* WAS: '' */
  }
  if (isset($data['node-ding_page-field_ding_page_paragraphs'])) {
    $data['node-ding_page-field_ding_page_paragraphs']['display']['teaser_no_overlay'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['allowed_bundles']['ding_help_front_box'] = -1; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['allowed_bundles']['ding_help_page_accordion'] = -1; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['allowed_bundles']['ding_help_page_body'] = -1; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['allowed_bundles']['ding_help_page_cta'] = -1; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['allowed_bundles']['ding_help_page_step'] = -1; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['allowed_bundles']['ding_help_page_step_by_step'] = -1; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['allowed_bundles']['kkb_newsletter'] = -1; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['allowed_bundles']['kkb_newsletter_reference'] = 'kkb_newsletter_reference'; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['bundle_weights']['ding_help_front_box'] = 13; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['bundle_weights']['ding_help_page_accordion'] = 14; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['bundle_weights']['ding_help_page_body'] = 15; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['bundle_weights']['ding_help_page_cta'] = 16; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['bundle_weights']['ding_help_page_step'] = 17; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['bundle_weights']['ding_help_page_step_by_step'] = 18; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['bundle_weights']['kkb_newsletter'] = 26; /* WAS: '' */
    $data['node-ding_page-field_ding_page_paragraphs']['settings']['bundle_weights']['kkb_newsletter_reference'] = 27; /* WAS: '' */
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
function kkb_newsletter_paragraphs_feature_paragraphs_info() {
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
