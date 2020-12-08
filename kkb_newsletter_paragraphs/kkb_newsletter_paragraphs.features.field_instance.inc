<?php
/**
 * @file
 * kkb_newsletter_paragraphs_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function kkb_newsletter_paragraphs_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-ding_event-field_event_newsletter'.
  $field_instances['node-ding_event-field_event_newsletter'] = array(
    'bundle' => 'ding_event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'alternative_layout_full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 19,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser_highlight' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser_no_overlay' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_newsletter',
    'label' => 'Newsletter',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'ding_help_front_box' => -1,
        'ding_help_page_accordion' => -1,
        'ding_help_page_body' => -1,
        'ding_help_page_cta' => -1,
        'ding_help_page_step' => -1,
        'ding_help_page_step_by_step' => -1,
        'ding_paragraphs_carousel' => -1,
        'ding_paragraphs_image' => -1,
        'ding_paragraphs_image_and_text' => -1,
        'ding_paragraphs_material_list' => -1,
        'ding_paragraphs_single_material' => -1,
        'ding_paragraphs_text' => -1,
        'ding_paragraphs_text_box' => -1,
        'kkb_newsletter' => -1,
        'kkb_newsletter_reference' => 'kkb_newsletter_reference',
      ),
      'bundle_weights' => array(
        'ding_help_front_box' => 2,
        'ding_help_page_accordion' => 3,
        'ding_help_page_body' => 4,
        'ding_help_page_cta' => 5,
        'ding_help_page_step' => 6,
        'ding_help_page_step_by_step' => 7,
        'ding_paragraphs_carousel' => 8,
        'ding_paragraphs_image' => 9,
        'ding_paragraphs_image_and_text' => 10,
        'ding_paragraphs_material_list' => 11,
        'ding_paragraphs_single_material' => 12,
        'ding_paragraphs_text' => 13,
        'ding_paragraphs_text_box' => 14,
        'kkb_newsletter' => 15,
        'kkb_newsletter_reference' => 16,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'node-newsletter_administration-field_newsletters'.
  $field_instances['node-newsletter_administration-field_newsletters'] = array(
    'bundle' => 'newsletter_administration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'alternative_layout_full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser_highlight' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser_no_overlay' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_newsletters',
    'label' => 'Newsletters',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'ding_help_front_box' => -1,
        'ding_help_page_accordion' => -1,
        'ding_help_page_body' => -1,
        'ding_help_page_cta' => -1,
        'ding_help_page_step' => -1,
        'ding_help_page_step_by_step' => -1,
        'ding_paragraphs_carousel' => -1,
        'ding_paragraphs_image' => -1,
        'ding_paragraphs_image_and_text' => -1,
        'ding_paragraphs_material_list' => -1,
        'ding_paragraphs_single_material' => -1,
        'ding_paragraphs_text' => -1,
        'ding_paragraphs_text_box' => -1,
        'kkb_newsletter' => 'kkb_newsletter',
        'kkb_newsletter_reference' => -1,
      ),
      'bundle_weights' => array(
        'ding_help_front_box' => 2,
        'ding_help_page_accordion' => 3,
        'ding_help_page_body' => 4,
        'ding_help_page_cta' => 5,
        'ding_help_page_step' => 6,
        'ding_help_page_step_by_step' => 7,
        'ding_paragraphs_carousel' => 8,
        'ding_paragraphs_image' => 9,
        'ding_paragraphs_image_and_text' => 10,
        'ding_paragraphs_material_list' => 11,
        'ding_paragraphs_single_material' => 12,
        'ding_paragraphs_text' => 13,
        'ding_paragraphs_text_box' => 14,
        'kkb_newsletter' => 15,
        'kkb_newsletter_reference' => -30,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_description'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_description'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_image'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_image'] = array(
    'bundle' => 'kkb_newsletter',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'oembed' => 0,
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'ding_content' => 0,
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
        ),
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 0,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => FALSE,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 0,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
      ),
      'type' => 'media_generic',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_image_color'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_image_color'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_image_color',
    'label' => 'Image background color',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_image_title'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_image_title'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_image_title',
    'label' => 'Image title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_submit'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_submit'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_submit',
    'label' => 'Submit',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_submit_b_color'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_submit_b_color'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_submit_b_color',
    'label' => 'Submit background color',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_submit_color'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_submit_color'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_submit_color',
    'label' => 'Submit color',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_text_bck_color'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_text_bck_color'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_text_bck_color',
    'label' => 'Text background color',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_text_color'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_text_color'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_text_color',
    'label' => 'Text color',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter-field_newsletter_title'.
  $field_instances['paragraphs_item-kkb_newsletter-field_newsletter_title'] = array(
    'bundle' => 'kkb_newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-kkb_newsletter_reference-field_newsletter'.
  $field_instances['paragraphs_item-kkb_newsletter_reference-field_newsletter'] = array(
    'bundle' => 'kkb_newsletter_reference',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_newsletter',
    'label' => 'Newsletter',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Image');
  t('Image background color');
  t('Image title');
  t('Newsletter');
  t('Newsletters');
  t('Submit');
  t('Submit background color');
  t('Submit color');
  t('Text background color');
  t('Text color');
  t('Title');

  return $field_instances;
}
