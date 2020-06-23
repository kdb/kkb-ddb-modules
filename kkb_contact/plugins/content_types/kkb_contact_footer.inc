<?php
/**
 * @file
 * Contact footer block.
 */

$plugin = [
  'title' => t('KKB Contact footer'),
  'description' => t('Adds a contact footer.'),
  'single' => TRUE,
  'render callback' => 'kkb_contact_kkb_contact_footer_content_type_render',
  'category' => t('Ding!'),
];

/**
 * Content type render function.
 */
function kkb_contact_kkb_contact_footer_content_type_render() {
  $node = menu_get_object();
  $language = !empty($node) ? $node->language : 'da';
  $title_default = $language === 'da' ? KKB_CONTACT_PAGE_PHONE_SECTION_BLOCK_TITLE_DEFAULT_DA : KKB_CONTACT_PAGE_PHONE_SECTION_BLOCK_TITLE_DEFAULT_EN;

  $block = new stdClass();
  // @todo should be translatable.
  $block->title = variable_get('kkb_contact_page_phone_section_block_title_' . $language, $title_default);
  $block->content = [
    '#theme' => 'kkb_contact_block',
  ];

  return $block;
}
