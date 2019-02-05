<?php
/**
 * @file
 * kkb_help.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function kkb_help_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_1cb6f884-5c0f-4327-887c-49fd064c26cf';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -13;
  $handler->conf = array(
    'title' => 'KKB Help',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ding_help_front' => 'ding_help_front',
              'ding_help_page' => 'ding_help_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = '25_50_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left_sidebar' => NULL,
      'main_content' => NULL,
      'right_sidebar' => NULL,
      'attachment_4_1' => NULL,
      'attachment_4_2' => NULL,
      'attachment_4_3' => NULL,
      'attachment_4_4' => NULL,
      'attachment_3_1' => NULL,
      'attachment_3_2' => NULL,
      'attachment_3_3' => NULL,
      'attachment_2_1' => NULL,
      'attachment_2_2' => NULL,
      'attachment_1_1' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b0fc21d5-1fdf-41e0-95f1-27757f5a1afa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e4886fe8-d474-4391-a41f-08cd86f1bf3d';
    $pane->panel = 'attachment_1_1';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ding_help_page' => 'ding_help_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'panels_breadcrumbs_admin_title' => '',
      'panels_breadcrumbs_state' => 0,
      'panels_breadcrumbs_titles' => '',
      'panels_breadcrumbs_paths' => '',
      'panels_breadcrumbs_home' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e4886fe8-d474-4391-a41f-08cd86f1bf3d';
    $display->content['new-e4886fe8-d474-4391-a41f-08cd86f1bf3d'] = $pane;
    $display->panels['attachment_1_1'][0] = 'new-e4886fe8-d474-4391-a41f-08cd86f1bf3d';
    $pane = new stdClass();
    $pane->pid = 'new-1c71c411-1441-4575-ad0e-d1cf1c034288';
    $pane->panel = 'attachment_1_1';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 0,
      'override_title_text' => 'lala',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1c71c411-1441-4575-ad0e-d1cf1c034288';
    $display->content['new-1c71c411-1441-4575-ad0e-d1cf1c034288'] = $pane;
    $display->panels['attachment_1_1'][1] = 'new-1c71c411-1441-4575-ad0e-d1cf1c034288';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-1c71c411-1441-4575-ad0e-d1cf1c034288';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_1cb6f884-5c0f-4327-887c-49fd064c26cf'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_286e0e62-2843-4901-9bf4-9cdf168c40a8';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Ding help category',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'help_category' => 'help_category',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = '25_50_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left_sidebar' => NULL,
      'main_content' => NULL,
      'right_sidebar' => NULL,
      'attachment_4_1' => NULL,
      'attachment_4_2' => NULL,
      'attachment_4_3' => NULL,
      'attachment_4_4' => NULL,
      'attachment_3_1' => NULL,
      'attachment_3_2' => NULL,
      'attachment_3_3' => NULL,
      'attachment_2_1' => NULL,
      'attachment_2_2' => NULL,
      'attachment_1_1' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '84a6738d-3185-4eb5-835f-2f8256f27728';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2b2bb586-ed20-4749-8bd5-6840b64eee3b';
    $pane->panel = 'attachment_1_1';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'panels_breadcrumbs_admin_title' => '',
      'panels_breadcrumbs_state' => 0,
      'panels_breadcrumbs_titles' => '',
      'panels_breadcrumbs_paths' => '',
      'panels_breadcrumbs_home' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2b2bb586-ed20-4749-8bd5-6840b64eee3b';
    $display->content['new-2b2bb586-ed20-4749-8bd5-6840b64eee3b'] = $pane;
    $display->panels['attachment_1_1'][0] = 'new-2b2bb586-ed20-4749-8bd5-6840b64eee3b';
    $pane = new stdClass();
    $pane->pid = 'new-5c425399-3256-4db9-8718-bb61837052fa';
    $pane->panel = 'attachment_1_1';
    $pane->type = 'entity_view';
    $pane->subtype = 'taxonomy_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_term_1',
      'override_title' => 1,
      'override_title_text' => '%term:name',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5c425399-3256-4db9-8718-bb61837052fa';
    $display->content['new-5c425399-3256-4db9-8718-bb61837052fa'] = $pane;
    $display->panels['attachment_1_1'][1] = 'new-5c425399-3256-4db9-8718-bb61837052fa';
    $pane = new stdClass();
    $pane->pid = 'new-1c794d27-0f43-4ff4-9572-e8e5f30d6f91';
    $pane->panel = 'attachment_1_1';
    $pane->type = 'views_panes';
    $pane->subtype = 'kkb_help-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1c794d27-0f43-4ff4-9572-e8e5f30d6f91';
    $display->content['new-1c794d27-0f43-4ff4-9572-e8e5f30d6f91'] = $pane;
    $display->panels['attachment_1_1'][2] = 'new-1c794d27-0f43-4ff4-9572-e8e5f30d6f91';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_286e0e62-2843-4901-9bf4-9cdf168c40a8'] = $handler;

  return $export;
}
