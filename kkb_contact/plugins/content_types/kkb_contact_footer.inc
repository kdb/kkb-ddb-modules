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
  $block = new stdClass();
  // @todo should be translatable.
  $block->title = 'Har du stadigvæk brug for hjælp?';
  $block->content = [
    '#theme' => 'kkb_contact_block',
  ];

  return $block;
}
