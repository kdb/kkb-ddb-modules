<?php
/**
 * @file
 * kkb_help.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function kkb_help_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'kkb_help';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'KKB Help';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Weight (field_fing_help_page_weight) */
  $handler->display->display_options['sorts']['field_fing_help_page_weight_value']['id'] = 'field_fing_help_page_weight_value';
  $handler->display->display_options['sorts']['field_fing_help_page_weight_value']['table'] = 'field_data_field_fing_help_page_weight';
  $handler->display->display_options['sorts']['field_fing_help_page_weight_value']['field'] = 'field_fing_help_page_weight_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Help category (field_ding_help_page_category) */
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['id'] = 'field_ding_help_page_category_tid';
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['table'] = 'field_data_field_ding_help_page_category';
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['field'] = 'field_ding_help_page_category_tid';
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ding_help_page_category_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ding_help_page' => 'ding_help_page',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_ding_help_page_category_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Help category (field_ding_help_page_category)',
    ),
  );
  $translatables['kkb_help'] = array(
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
    t('Alle'),
    t('Content pane'),
    t('View panes'),
  );
  $export['kkb_help'] = $view;

  return $export;
}
