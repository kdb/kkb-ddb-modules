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
  // Keep track of existing images.
  $images = [];

  uasort($form_state['teasers'], 'drupal_sort_weight');

  $form['kkb_contact_page_title'] = [
    '#type' => 'textfield',
    '#title' => t('Page title'),
    '#default_value' => variable_get('kkb_contact_page_title', KKB_CONTACT_PAGE_TITLE_DEFAULT),
  ];

  $form['teasers_wrapper'] = [
    '#type' => 'fieldset',
    '#title' => t('Teasers'),
    '#prefix' => '<div id="kkb-contact-teasers">',
    '#suffix' => '</div>',
  ];

  $form['teasers_wrapper']['kkb_contact_teasers'] = [
    '#tree' => TRUE,
    '#theme' => ['kkb_contact_settings_teasers'],
  ];

  foreach ($form_state['teasers'] as $key => $teaser) {
    if ($teaser['image']) {
      $images[] = $teaser['image'];
    }
    if (isset($teaser['deleted'])) {
      // We're keeping deleted items around to retain indexing (else form_error
      // gets into trouble), and because we might need to delete the image.
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
              'body' => KKB_CONTACT_TEASERS_FOOTER_VALUE_DEFAULT,
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

  $form['phone_wrapper']['kkb_contact_page_phone_section_title'] = [
    '#type' => 'textfield',
    '#title' => t('Section title'),
    '#default_value' => variable_get('kkb_contact_page_phone_section_title', KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT),
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

  $form['phone_wrapper']['first_box']['kkb_contact_page_phone_first_left_side'] = [
    '#type' => 'textarea',
    '#title' => t('Left'),
    '#default_value' => variable_get('kkb_contact_page_phone_first_left_side', KKB_CONTACT_PAGE_PHONE_FIRST_LEFT_SIDE_DEFAULT),
    '#cols' => 40,
    '#rows' => 4,
  ];

  $form['phone_wrapper']['first_box']['kkb_contact_page_phone_first_right_side'] = [
    '#type' => 'textarea',
    '#title' => t('Right'),
    '#default_value' => variable_get('kkb_contact_page_phone_first_right_side', KKB_CONTACT_PAGE_PHONE_FIRST_RIGHT_SIDE_DEFAULT),
    '#cols' => 40,
    '#rows' => 4,
  ];

  $form['phone_wrapper']['second_box'] = [
    '#type' => 'fieldset',
    '#title' => t('Second box'),
  ];

  $form['phone_wrapper']['second_box']['kkb_contact_page_phone_second_top'] = [
    '#type' => 'textfield',
    '#title' => t('Top'),
    '#default_value' => variable_get('kkb_contact_page_phone_second_top', KKB_CONTACT_PAGE_PHONE_SECOND_TOP_DEFAULT),
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

    $form['write_wrapper'][$box . '_box']['kkb_contact_page_write_' . $box . '_link_text'] = [
      '#type' => 'textfield',
      '#title' => t('Link text'),
      '#default_value' => variable_get('kkb_contact_page_write_' . $box . '_link_text', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_LINK_TEXT_DEFAULT')),
      '#size' => 50,
    ];

  }

  $form['#attached'] = [
    'css' => [drupal_get_path('module', 'kkb_contact') . '/css/kkb_contact.admin.css'],
    'js' => [drupal_get_path('module', 'kkb_contact') . '/kkb_contact.admin.js'],
  ];

  $form_state['images'] = $images;

  $form['#submit'][] = 'kkb_contact_settings_submit';

  return system_settings_form($form);
}

/**
 * Submit handler for settings form.
 */
function kkb_contact_settings_submit($form, &$form_state) {
  $teasers = [];
  $submitted_teasers = $form_state['values']['kkb_contact_teasers'];
  $images = array_flip($form_state['images']);

  // Delete images of deleted teasers.
  foreach ($form_state['teasers'] as $key => $teaser) {
    if (isset($teaser['deleted'])) {
      if ($teaser['image']) {
        $file = file_load($teaser['image']);
        if ($file) {
          file_usage_delete($file, 'kkb_contact', 'kkb_contact_teasers', $key, 0);
          file_delete($file);
        }
        unset($images[$teaser['image']]);
      }
    }
  }

  foreach ($submitted_teasers as $key => $teaser) {
    // If the image is new, make it permanent.
    if ($teaser['image'] && !isset($images[$teaser['image']])) {
      $file = file_load($teaser['image']);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'kkb_contact', 'kkb_contact_teasers', $key);
    }
    else {
      unset($images[$teaser['image']]);
    }
    $teasers[] = $teaser;
  }

  if (!empty($images)) {
    // Delete dangling images. Replacing the image of a teaser before hitting
    // save will replace the fid, but not delete the file.
    foreach ($images as $image) {
      $file = file_load($image);
      if ($file) {
        file_usage_delete($file, 'kkb_contact');
        file_delete($file);
      }
    }
  }

  uasort($teasers, 'drupal_sort_weight');

  // Set value for system_settings_form to save.
  form_set_value($form['teasers_wrapper']['kkb_contact_teasers'], $teasers, $form_state);
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
  ];

  $form['body'] = [
    '#type' => 'text_format',
    '#title' => t('Body'),
    '#default_value' => $teaser['body']['value'],
    '#format' => $teaser['body']['format'],
  ];

  $form['image'] = array(
    '#title' => t('Image'),
    '#type' => 'managed_file',
    '#upload_validators' => array('file_validate_extensions' => array('jpg jpeg png gif')),
    '#upload_location' => 'public://contact/',
    '#default_value' => $teaser['image'],
  );

  $form['link'] = [
    '#type' => 'textfield',
    '#title' => t('Link'),
    '#default_value' => $teaser['link'],
    '#size' => 50,
  ];

  $form['link_text'] = [
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => $teaser['link_text'],
    '#size' => 50,
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

  $form['remove'] = [
    '#type' => 'submit',
    '#value' => t('Remove'),
    '#remove_key' => $key,
    '#name' => 'remove_' . $key,
    '#attributes' => [
      'class' => [
        'remove',
      ],
    ],
    '#submit' => ['kkb_contact_settings_remove'],
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
    'body' => [
      'value' => '',
      'format' => NULL,
    ],
    'image' => 0,
    'link' => '',
    'link_text' => '',
    'weight' => 0,
    'region' => 'enabled',
  ];
  $form_state['rebuild'] = TRUE;
}

/**
 * AJAX callback for "remove" button.
 */
function kkb_contact_settings_remove($form, &$form_state) {
  if (isset($form_state['triggering_element']['#remove_key'])) {
    $key = $form_state['triggering_element']['#remove_key'];
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