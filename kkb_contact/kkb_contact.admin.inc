<?php

/**
 * @file
 * Administrative pages for kkb_contact.
 */

/**
 * Settings form builder.
 */
function kkb_contact_settings($form, &$form_state) {

  if (!isset($form_state['teasers'])) {
    $form_state['teasers'] = variable_get('kkb_contact_teasers', []);
  }

  uasort($form_state['teasers'], 'drupal_sort_weight');

  $form['kkb_contact_page_title'] = [
    '#type' => 'textfield',
    '#title' => t('Page title'),
    '#default_value' => variable_get('kkb_contact_page_title', KKB_CONTACT_PAGE_TITLE_DEFAULT),
  ];

  $form['kkb_contact_page_news'] = [
    '#type' => 'entityreference',
    '#era_entity_type' => 'node',
    '#era_bundles' => ['ding_news'],
    '#era_cardinality' => 1,
    '#title' => t('News message'),
    '#default_value' => variable_get('kkb_contact_page_news', KKB_CONTACT_PAGE_NEWS_DEFAULT),
    '#size' => 50,
    '#required' => FALSE,
  ];

  $form['teasers_wrapper'] = [
    '#type' => 'fieldset',
    '#title' => t('Teasers'),
    '#prefix' => '<div id="kkb-contact-teasers">',
    '#suffix' => '</div>',
  ];

  $header = variable_get('kkb_contact_teasers_header',
            [
              'value' => KKB_CONTACT_TEASERS_HEADER_VALUE_DEFAULT,
              'format' => KKB_CONTACT_TEASERS_HEADER_FORMAT_DEFAULT,
            ]);

  $form['teasers_wrapper']['kkb_contact_teasers_header'] = [
    '#type' => 'text_format',
    '#title' => t('Header'),
    '#default_value' => $header['value'],
    '#format' => $header['format'],
  ];

  $form['teasers_wrapper']['kkb_contact_teasers'] = [
    '#tree' => TRUE,
    '#theme' => ['kkb_contact_settings_teasers'],
  ];

  foreach ($form_state['teasers'] as $key => $teaser) {
    if (isset($teaser['deleted'])) {
      // We're keeping deleted items around to retain indexing (else form_error
      // gets into trouble).
      continue;
    }

    $form['teasers_wrapper']['kkb_contact_teasers'][$key] = kkb_contact_settings_teaser_form($teaser, $key);
  }

  $form['teasers_wrapper']['add_more'] = [
    '#type' => 'submit',
    '#value' => t('Add one more'),
    '#submit' => ['kkb_contact_settings_add_one'],
    '#ajax' => [
      'callback' => 'kkb_contact_settings_callback',
      'wrapper' => 'kkb-contact-teasers',
      'method' => 'replace',
      'effect' => 'fade',
    ],
  ];

  $footer = variable_get('kkb_contact_teasers_footer',
            [
              'value' => KKB_CONTACT_TEASERS_FOOTER_VALUE_DEFAULT,
              'format' => KKB_CONTACT_TEASERS_FOOTER_FORMAT_DEFAULT,
            ]);

  $form['teasers_wrapper']['kkb_contact_teasers_footer'] = [
    '#type' => 'text_format',
    '#title' => t('Footer'),
    '#default_value' => $footer['value'],
    '#format' => $footer['format'],
  ];

  $form['phone_wrapper'] = [
    '#type' => 'fieldset',
    '#title' => t('Phone section'),
  ];

  $form['phone_wrapper']['kkb_contact_page_phone_section_title_da'] = [
    '#type' => 'textfield',
    '#title' => t('DA: Section title'),
    '#default_value' => variable_get('kkb_contact_page_phone_section_title_da', KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT_DA),
  ];

  $form['phone_wrapper']['kkb_contact_page_phone_section_title_en'] = [
    '#type' => 'textfield',
    '#title' => t('EN: Section title'),
    '#default_value' => variable_get('kkb_contact_page_phone_section_title_en', KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT_EN),
  ];

  $form['phone_wrapper']['first_box'] = [
    '#type' => 'fieldset',
    '#title' => t('First box'),
  ];

  $form['phone_wrapper']['first_box']['kkb_contact_page_phone_first_title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('kkb_contact_page_phone_first_title', KKB_CONTACT_PAGE_PHONE_FIRST_TITLE_DEFAULT),
  ];

  $left_box = variable_get('kkb_contact_page_phone_first_left_side',
              [
                'value' => KKB_CONTACT_PAGE_PHONE_FIRST_LEFT_SIDE_VALUE_DEFAULT,
                'format' => KKB_CONTACT_PAGE_PHONE_FIRST_LEFT_SIDE_FORMAT_DEFAULT,
              ]);

  $form['phone_wrapper']['first_box']['kkb_contact_page_phone_first_left_side'] = [
    '#type' => 'text_format',
    '#title' => t('Left'),
    '#default_value' => $left_box['value'],
    '#format' => $left_box['format'],
  ];

  $form['phone_wrapper']['first_box']['kkb_contact_page_phone_first_right_side_da'] = [
    '#type' => 'textarea',
    '#title' => t('DA: Right'),
    '#default_value' => variable_get('kkb_contact_page_phone_first_right_side_da', KKB_CONTACT_PAGE_PHONE_FIRST_RIGHT_SIDE_DEFAULT_DA),
    '#cols' => 40,
    '#rows' => 4,
  ];

  $form['phone_wrapper']['first_box']['kkb_contact_page_phone_first_right_side_en'] = [
    '#type' => 'textarea',
    '#title' => t('EN: Right'),
    '#default_value' => variable_get('kkb_contact_page_phone_first_right_side_en', KKB_CONTACT_PAGE_PHONE_FIRST_RIGHT_SIDE_DEFAULT_EN),
    '#cols' => 40,
    '#rows' => 4,
  ];

  $form['phone_wrapper']['second_box'] = [
    '#type' => 'fieldset',
    '#title' => t('Second box'),
  ];

  $form['phone_wrapper']['second_box']['kkb_contact_page_phone_second_phone'] = [
    '#type' => 'textfield',
    '#title' => t('Phone number'),
    '#default_value' => variable_get('kkb_contact_page_phone_second_phone', KKB_CONTACT_PAGE_PHONE_SECOND_PHONE_DEFAULT),
  ];

  $form['write_wrapper'] = [
    '#type' => 'fieldset',
    '#title' => t('Write section'),
  ];

  $form['write_wrapper']['kkb_contact_page_write_section_title'] = [
    '#type' => 'textfield',
    '#title' => t('Section title'),
    '#default_value' => variable_get('kkb_contact_page_write_section_title', KKB_CONTACT_PAGE_WRITE_SECTION_TITLE_DEFAULT),
  ];

  $form['write_wrapper']['kkb_contact_page_write_da'] = [
    '#type' => 'textfield',
    '#title' => t('DA: Write'),
    '#default_value' => variable_get('kkb_contact_page_write_da', KKB_CONTACT_PAGE_PHONE_WRITE_DEFAULT_DA),
  ];

  $form['write_wrapper']['kkb_contact_page_write_en'] = [
    '#type' => 'textfield',
    '#title' => t('EN: Write'),
    '#default_value' => variable_get('kkb_contact_page_write_en', KKB_CONTACT_PAGE_PHONE_WRITE_DEFAULT_EN),
  ];

  foreach (['first' => t('First box'), 'second' => t('Second box')] as $box => $title) {
    $form['write_wrapper'][$box . '_box'] = [
      '#type' => 'fieldset',
      '#title' => $title,
    ];

    $form['write_wrapper'][$box . '_box']['kkb_contact_page_write_' . $box . '_title'] = [
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => variable_get('kkb_contact_page_write_' . $box . '_title', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_TITLE_DEFAULT')),
    ];

    $body = variable_get('kkb_contact_page_write_' . $box . '_body',
            [
              'value' => constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_BODY_VALUE_DEFAULT'),
              'format' => constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_BODY_FORMAT_DEFAULT'),
            ]);

    $form['write_wrapper'][$box . '_box']['kkb_contact_page_write_' . $box . '_body'] = [
      '#type' => 'text_format',
      '#title' => t('Body'),
      '#default_value' => $body['value'],
      '#format' => $body['format'],
    ];

    $form['write_wrapper'][$box . '_box']['kkb_contact_page_write_' . $box . '_link'] = [
      '#type' => 'textfield',
      '#title' => t('Link'),
      '#default_value' => variable_get('kkb_contact_page_write_' . $box . '_link', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_LINK_DEFAULT')),
      '#size' => 50,
    ];

  }

  $form['#attached'] = [
    'css' => [drupal_get_path('module', 'kkb_contact') . '/css/kkb_contact.admin.css'],
    'js' => [drupal_get_path('module', 'kkb_contact') . '/kkb_contact.admin.js'],
  ];

  $form['#validate'][] = 'kkb_contact_settings_validate';
  $form['#submit'][] = 'kkb_contact_settings_submit';

  return system_settings_form($form);
}

/**
 * Validation handler for settings from.
 */
function kkb_contact_settings_validate($form, &$form_state) {
  foreach ($form_state['values']['kkb_contact_teasers'] as $key => $teaser) {
    if (drupal_strlen($teaser['body']) > 160) {
      form_error($form['teasers_wrapper']['kkb_contact_teasers'][$key]['body'], t('max 160 characters'));
    }
  }
}

/**
 * Submit handler for settings form.
 */
function kkb_contact_settings_submit($form, &$form_state) {
  $submitted_teasers = $form_state['values']['kkb_contact_teasers'];

  uasort($submitted_teasers, 'drupal_sort_weight');

  // Set value for system_settings_form to save.
  form_set_value($form['teasers_wrapper']['kkb_contact_teasers'], $submitted_teasers, $form_state);
}

/**
 * Return teaser sub-form.
 */
function kkb_contact_settings_teaser_form($teaser, $key) {
  $form = [];

  $form['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $teaser['title'],
    '#size' => 50,
    '#required' => TRUE,
  ];

  $form['body'] = [
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => $teaser['body'],
  ];

  $form['link'] = [
    '#type' => 'textfield',
    '#title' => t('Link'),
    '#default_value' => $teaser['link'],
    '#size' => 50,
    '#required' => TRUE,
  ];

  $form['weight'] = [
    '#type' => 'weight',
    '#delta' => 10,
    '#default_value' => $teaser['weight'],
  ];

  $form['region'] = [
    '#type' => 'select',
    '#default_value' => $teaser['region'],
    '#title_display' => 'invisible',
    '#options' => [
      'enabled' => t('Enabled'),
      'disabled' => t('Disabled'),
    ],
  ];

  $form['delete'] = [
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#delete_key' => $key,
    '#name' => 'delete_' . $key,
    '#attributes' => [
      'class' => [
        'delete',
      ],
    ],
    '#submit' => ['kkb_contact_settings_delete'],
    '#ajax' => [
      'callback' => 'kkb_contact_settings_callback',
      'wrapper' => 'kkb-contact-teasers',
      'method' => 'replace',
      'effect' => 'fade',
    ],
  ];

  return $form;
}

/**
 * AJAX callback for "add more" button.
 */
function kkb_contact_settings_add_one($form, &$form_state) {
  $key = max(array_keys($form_state['teasers'])) + 1;
  $form_state['teasers'][$key] = [
    'title' => '',
    'body' => '',
    'link' => '',
    'weight' => 0,
    'region' => 'enabled',
  ];
  $form_state['rebuild'] = TRUE;
}

/**
 * AJAX callback for "delete" button.
 */
function kkb_contact_settings_delete($form, &$form_state) {
  if (isset($form_state['triggering_element']['#delete_key'])) {
    $key = $form_state['triggering_element']['#delete_key'];
    // Mark as deleted.
    $form_state['teasers'][$key]['deleted'] = TRUE;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * AJAX responder for field addition/removal fields.
 *
 * @param array $form
 *   Form.
 *
 * @return array
 *   Changed field to be updated.
 */
function kkb_contact_settings_callback(array $form, array &$form_state) {
  return $form['teasers_wrapper'];
}

function kkb_contact_variables_form() {
  return drupal_get_form('variable_module_form', 'kkb_contact');
}
