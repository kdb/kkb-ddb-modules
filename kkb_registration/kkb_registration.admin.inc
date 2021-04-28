<?php

/**
 * @file
 * Administration for kkb_registration.
 */

/**
 * Settings form.
 */
function kkb_registration_admin_form($form, &$form_state) {
  drupal_add_css(drupal_get_path('module', 'kkb_registration') . '/css/kkb_registration_admin.css');

  // Because we have many fields with the same values, we have to set
  // #tree to be able to access them.
  $form['#tree'] = TRUE;

  $form['languages'] = [
    '#type' => 'vertical_tabs',
  ];

  $form_key_da = 'kkb_registration_da';
  $form_key_en = 'kkb_registration_en';

  $form[$form_key_da] = [
    '#type' => 'fieldset',
    '#title' => t('Danish'),
    '#collapsible' => TRUE,
    '#group' => 'languages'
  ];

  $form[$form_key_en] = [
    '#type' => 'fieldset',
    '#title' => t('English'),
    '#collapsible' => TRUE,
    '#group' => 'languages'
  ];

  _kkb_registration_add_lang_fields($form, $form_state, 'da');
  _kkb_registration_add_lang_fields($form, $form_state, 'en');

  $form['#submit'][] = 'kkb_registration_admin_form_submit';

  return system_settings_form($form);
}

/**
 * We have a list of fields that are repeated per supported language.
 */
function _kkb_registration_add_lang_fields(&$form, &$form_state, $lang_key) {
  $form_lang_key = 'kkb_registration_' . $lang_key;

  $values = variable_get($form_lang_key);

  $form[$form_lang_key]['show'] = [
    '#type' => 'checkbox',
    '#title' => t('Show this language section'),
    '#default_value' => isset($values['show']) ? $values['show'] : TRUE,
  ];

  $form[$form_lang_key]['image'] = [
    '#type' => 'media',
    '#theme' => 'media_widget',
    '#title' => t('Image'),
    '#default_value' => !empty($values['image']) ? $values['image'] : NULL,
    '#media_options' => [
      'global' => [
        'file_directory' => 'kkb_registration',
        'file_extensions' => 'jpg jpeg',
        'max_filesize' => '4 MB',
        'uri_scheme' => 'public',
        'types' => ['image'],
        'schemes' => [
          'public' => 'public',
        ],
      ],
    ],
  ];

  $form[$form_lang_key]['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => !empty($values['title']) ? $values['title'] : NULL,
  ];

  $form[$form_lang_key]['subtitle'] = [
    '#type' => 'textfield',
    '#title' => t('Subtitle'),
    '#default_value' => !empty($values['subtitle']) ? $values['subtitle'] : NULL,
  ];

  $body = !empty($values['body']) ? $values['body'] : NULL;

  $form[$form_lang_key]['body'] = [
    '#type' => 'text_format',
    '#title' => t('Body'),
    '#default_value' => !empty($body['value']) ? $body['value'] : NULL,
    '#format'=> 'ding_wysiwyg',
  ];

  $form[$form_lang_key]['infos'] = [
    '#type' => 'container',
    '#title' => t('Infos'),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="infos-fieldset-wrapper-' . $lang_key . '">',
    '#suffix' => '</div>',
  ];

  $infos = !empty($values['infos']) ? $values['infos'] : [];

  if (empty($form_state['num_infos_' . $lang_key])) {
    $info_count = count($infos);
    $form_state['num_infos_' . $lang_key] = !empty($info_count) ? $info_count : 1;
  }

  for ($i = 0; $i < $form_state['num_infos_' . $lang_key]; $i++) {
    $form[$form_lang_key]['infos'][$i] = [
      '#type' => 'fieldset',
      '#title' => t('Info-box'),
      '#attributes' => [
        'class' => ['kkb-registration__admin-info'],
      ],
    ];

    $form[$form_lang_key]['infos'][$i]['delete'] = [
      '#type' => 'checkbox',
      '#title' => t('Delete this info-box when saving'),
    ];

    $form[$form_lang_key]['infos'][$i]['anchor'] = [
      '#type' => 'textfield',
      '#title' => t('Anchor ID'),
      '#description' => t(
        'An anchor ID can be used to link direct to this info box, e.g. !example When you save this form, you can view the constructed anchor ID here.',
        [
          '!example' => '"/opretbruger#<strong>english-info</strong>"<br/>'
        ]
      ),
      '#default_value' => !empty($infos[$i]['anchor']) ? $infos[$i]['anchor'] : NULL,
    ];

    $form[$form_lang_key]['infos'][$i]['title'] = [
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => !empty($infos[$i]['title']) ? $infos[$i]['title'] : NULL,
    ];

    $form[$form_lang_key]['infos'][$i]['body'] = [
      '#type' => 'text_format',
      '#title' => t('Body'),
      '#default_value' => !empty($infos[$i]['body']['value']) ? $infos[$i]['body']['value'] : NULL,
      '#format'=> 'ding_wysiwyg',
    ];

    $form[$form_lang_key]['infos'][$i]['link_title'] = [
      '#type' => 'textfield',
      '#title' => t('Link title'),
      '#default_value' => !empty($infos[$i]['link_title']) ? $infos[$i]['link_title'] : NULL,
    ];

    $form[$form_lang_key]['infos'][$i]['link_url'] = [
      '#type' => 'textfield',
      '#title' => t('Link URL'),
      '#default_value' => !empty($infos[$i]['link_url']) ? $infos[$i]['link_url'] : NULL,
    ];

    $form[$form_lang_key]['infos'][$i]['link_target'] = [
      '#type' => 'select',
      '#title' => t('Link "target"'),
      '#default_value' => !empty($infos[$i]['link_target']) ? $infos[$i]['link_target'] : '_blank',
      '#options' => [
        '_blank' => t('Open in a new tab ("_blank")'),
        '_self' => t('Open in the same tab ("_self")'),
      ],
      '#required' => TRUE,
    ];
  }

  $form[$form_lang_key]['infos']['add_name'] = [
    '#type' => 'submit',
    '#value' => t('Add another info-box'),
    '#submit' => [
      'kkb_registration_admin_add_info_' . $lang_key,
    ],
    // See the examples in ajax_example.module for more details on the
    // properties of #ajax.
    '#ajax' => [
      'callback' => 'kkb_registration_admin_add_info_callback_' . $lang_key,
      'wrapper' => 'infos-fieldset-wrapper-' . $lang_key,
    ],
  ];

  return $form;
}

/**
 * Used in relation to the "add one more infobox" for the danish section
 */
function kkb_registration_admin_add_info_da($form, &$form_state) {
  $form_state['num_infos_da']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Used in relation to the "add one more infobox" for the english section
 */
function kkb_registration_admin_add_info_en($form, &$form_state) {
  $form_state['num_infos_en']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Used in relation to the "add one more infobox" for the danish section
 */
function kkb_registration_admin_add_info_callback_da($form, $form_state) {
  return $form['kkb_registration_da']['infos'];
}

/**
 * Used in relation to the "add one more infobox" for the english section
 */
function kkb_registration_admin_add_info_callback_en($form, $form_state) {
  return $form['kkb_registration_en']['infos'];
}

/**
 * Submit handler for settings form.
 *
 * Some magic is happening behind the scenes in this function.
 * Because we're using a system_settings_form, the outer fields actually
 * gets saved by default - so even without this form_submit(), data would
 * still be saved in e.g. kkb_registration_da
 *
 * We just use this function to tweak some of the data before it gets saved.
 */
function kkb_registration_admin_form_submit(&$form, &$form_state) {
  // There is some magic happening behind the scenes in this funciton
  $form_keys = ['kkb_registration_da', 'kkb_registration_en'];

  foreach ($form_keys as $form_key) {
    if (empty($form_state['values'][$form_key])) {
      continue;
    }

    // We need to do some things to our image, to make the new one
    // permanent, and trigger a deletion of any old images.
    $old_values = variable_get($form_key, NULL);

    $old_fid = !empty($old_values['image']) ? $old_values['image'] : NULL;
    $fid = !empty($form_state['values'][$form_key]['image']) ?
      $form_state['values'][$form_key]['image'] : NULL;

    if ($old_fid !== $fid) {
      // Removing our old file.
      if ($old_file = file_load($old_fid)) {
        $old_file->status = 0;
        $old_file = file_save($old_file);
        file_usage_delete($old_file, 'kkb_registration');
      }

      // Adding our new (possible) file.
      // Notice that we set it as permanent + add usage to make sure it doesnt
      // get purged.
      if ($file = file_load($fid)) {
        $file->status = FILE_STATUS_PERMANENT;
        $file = file_save($file);

        file_usage_add($file, 'kkb_registration', 'kkb_registration', 1);
      }
    }

    $infos = $form_state['values'][$form_key]['infos'];
    $anchors = [];

    // Looping through info boxes to:
    // - Delete the ones that are set for deletion.
    // - Cleaning up and preparing the anchors.
    foreach ($infos as $info_key => $info) {
      if ($info['delete']) {
        unset($infos[$info_key]);

        continue;
      }

      if (!empty($info['anchor'])) {
        // By using clean_css, we make sure that the anchor is valid for URLs.
        $anchor_cleaned = drupal_html_id($info['anchor']);

        $anchor_cleaned = strtolower($anchor_cleaned);

        // Making sure anchor IDs are unique.
        if (in_array($anchor_cleaned, $anchors)) {
          // Yes, this mean it can result in #anchorlink0000 but it's silly to
          // add a bunch of logic to increment the number for an edgecase.
          $anchor_cleaned .= '0';
        }

        $infos[$info_key]['anchor'] = $anchor_cleaned;
        $anchors[] = $anchor_cleaned;
      }
    }

    // Resetting the values, after we've been unsetting elements.
    // When re-setting it on $form_state, Drupal takes care of saving it with
    // variable_set().
    $form_state['values'][$form_key]['infos'] = array_values($infos);

    $url = url(KKB_REGISTRATION_URL,  ['absolute' => TRUE]);

    cache_clear_all($url, 'cache_page');
  }
}
