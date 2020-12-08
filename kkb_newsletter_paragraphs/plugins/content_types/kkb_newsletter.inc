<?php

$plugin = array(
  'title' => t('KKB Newsletter'),
  'description' => t('Display a newsletter signup banner'),
  'single' => TRUE,
//  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'kkb_newsletter_content_type_edit_form',
  'render callback' => 'kkb_newsletter_content_type_render',
  'category' => t('Ding!'),
);

function kkb_newsletter_content_type_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  if (empty($conf['kkb_newsletter_paragraph_item_id'])) {
    return $block;
  }

  $paragraphs = entity_load('paragraphs_item', array($conf['kkb_newsletter_paragraph_item_id']));

  if (empty($paragraphs)) {
    return $block;
  }

  $paragraphs_view = entity_view('paragraphs_item', $paragraphs, 'full');

  $content = $paragraphs_view['paragraphs_item'][$conf['kkb_newsletter_paragraph_item_id']];

  $block->title = t('Newsletter');
  $block->content = $content;

  return $block;
}

/**
 * Edit form callback for the content type.
 */
function kkb_newsletter_content_type_edit_form($form, &$form_state) {
  $query = new EntityFieldQuery();

  $query
    ->entityCondition('entity_type', 'paragraphs_item', '=')
    ->propertyCondition('bundle', 'kkb_newsletter', '=');

  $result = $query->execute();

  $ids = array();
  foreach ($result as $item) {
    $ids[] = array_keys($item)[0];
  }

  $paragraphs = entity_load('paragraphs_item', $ids);

  $options = array();
  foreach ($paragraphs as $paragraph) {
    $paragraph_wrapper = entity_metadata_wrapper('paragraphs_item', $paragraph);
    $id = $paragraph_wrapper->item_id->value();
    $options[$id] = $paragraph_wrapper->field_newsletter_title->value() . ' [' . $id  . ']';
  }

  $conf = $form_state['conf'];

  $form['kkb_newsletter_paragraph_item_id'] = array(
    '#type' => 'radios',
    '#title' => t('Choose a newsletter'),
    '#options' => $options,
    '#required' => TRUE,
    '#default_value' =>  isset($conf['kkb_newsletter_paragraph_item_id']) ? $conf['kkb_newsletter_paragraph_item_id'] : NULL,
  );

  return $form;
}

/**
 * Implements hook_content_type_edit_form_submit().
 */
function kkb_newsletter_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['kkb_newsletter_paragraph_item_id'] = $form_state['values']['kkb_newsletter_paragraph_item_id'];
}
