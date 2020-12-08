<?php
/**
 * @file
 * kkb_newsletter_paragraphs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kkb_newsletter_paragraphs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'newsletter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'paragraphs_item';
  $view->human_name = 'Newsletter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Paragraphs item: Paragraphs item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'paragraphs_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Field: Paragraphs item: Title */
  $handler->display->display_options['fields']['field_newsletter_title']['id'] = 'field_newsletter_title';
  $handler->display->display_options['fields']['field_newsletter_title']['table'] = 'field_data_field_newsletter_title';
  $handler->display->display_options['fields']['field_newsletter_title']['field'] = 'field_newsletter_title';
  /* Filter criterion: Paragraphs item: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'paragraphs_item';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'kkb_newsletter' => 'kkb_newsletter',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_newsletter_title' => 'field_newsletter_title',
    'item_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['newsletter'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Paragraphs item ID'),
    t('.'),
    t(','),
    t('Title'),
    t('Entity Reference'),
  );
  $export['newsletter'] = $view;

  return $export;
}
