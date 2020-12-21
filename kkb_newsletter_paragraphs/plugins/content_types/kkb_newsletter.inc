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
    ->entityCondition('entity_type', 'node', '=')
    ->entityCondition('bundle', 'newsletter_administration', '=');

  $result = $query->execute();

  $ids = array();
  foreach ($result['node'] as $item) {
    $ids[] =$item->nid;
  }

  $entities = entity_load('node', $ids);

  $options = array();
  foreach ($entities as $entity) {
    $node_wrapper = entity_metadata_wrapper('node', $entity);
    $id = $node_wrapper->field_newsletters->value()->item_id;
    $options[$id] = $node_wrapper->title->value();
  }

  $conf = $form_state['conf'];

  $form['kkb_newsletter_paragraph_item_id'] = array(
    '#type' => 'select',
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
