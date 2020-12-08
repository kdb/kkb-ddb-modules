<?php
/**
 * @file
 * kkb_newsletter_paragraphs.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function kkb_newsletter_paragraphs_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_base
  $overrides["field_base.field_ding_page_paragraphs.foreign keys"]["DELETED"] = TRUE;

  // Exported overrides for: field_instance
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.display|teaser_no_overlay"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|allowed_bundles|ding_help_front_box"] = 1;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|allowed_bundles|ding_help_page_accordion"] = 1;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|allowed_bundles|ding_help_page_body"] = 1;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|allowed_bundles|ding_help_page_cta"] = 1;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|allowed_bundles|ding_help_page_step"] = 1;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|allowed_bundles|ding_help_page_step_by_step"] = 1;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|allowed_bundles|kkb_newsletter"] = 1;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|allowed_bundles|kkb_newsletter_reference"] = 'kkb_newsletter_reference';
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|bundle_weights|ding_help_front_box"] = 13;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|bundle_weights|ding_help_page_accordion"] = 14;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|bundle_weights|ding_help_page_body"] = 15;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|bundle_weights|ding_help_page_cta"] = 16;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|bundle_weights|ding_help_page_step"] = 17;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|bundle_weights|ding_help_page_step_by_step"] = 18;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|bundle_weights|kkb_newsletter"] = 26;
  $overrides["field_instance.node-ding_news-field_ding_news_paragraphs.settings|bundle_weights|kkb_newsletter_reference"] = 27;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.display|teaser_no_overlay"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|allowed_bundles|ding_help_front_box"] = -1;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|allowed_bundles|ding_help_page_accordion"] = -1;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|allowed_bundles|ding_help_page_body"] = -1;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|allowed_bundles|ding_help_page_cta"] = -1;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|allowed_bundles|ding_help_page_step"] = -1;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|allowed_bundles|ding_help_page_step_by_step"] = -1;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|allowed_bundles|kkb_newsletter"] = -1;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|allowed_bundles|kkb_newsletter_reference"] = 'kkb_newsletter_reference';
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|bundle_weights|ding_help_front_box"] = 13;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|bundle_weights|ding_help_page_accordion"] = 14;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|bundle_weights|ding_help_page_body"] = 15;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|bundle_weights|ding_help_page_cta"] = 16;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|bundle_weights|ding_help_page_step"] = 17;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|bundle_weights|ding_help_page_step_by_step"] = 18;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|bundle_weights|kkb_newsletter"] = 26;
  $overrides["field_instance.node-ding_page-field_ding_page_paragraphs.settings|bundle_weights|kkb_newsletter_reference"] = 27;

 return $overrides;
}
