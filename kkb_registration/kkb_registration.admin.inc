<?php

/**
 * @file
 * Administration for kkb_registration.
 */

define('KKB_REGISTRATION_INFOS_KEY', 'kkb_registration_infos');

/**
 * Settings form.
 */
function kkb_registration_admin_form($form, &$form_state) {
  // Because we have many fields with the same values, we have to set
  // #tree to be able to access them.
  $form['#tree'] = TRUE;

  $form['kkb_registration_image'] = array(
    '#type' => 'media',
    '#theme' => 'media_widget',
    '#title' => t('Image'),
    '#default_value' => variable_get('kkb_registration_image', NULL),
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
  );

  $form['kkb_registration_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('kkb_registration_title', NULL),
  );

  $form['kkb_registration_subtitle'] = array(
    '#type' => 'textfield',
    '#title' => t('Subtitle'),
    '#default_value' => variable_get('kkb_registration_subtitle', NULL),
  );


  $body = variable_get('kkb_registration_body', NULL);

  $form['kkb_registration_body'] = array(
    '#type' => 'text_format',
    '#title' => t('Body'),
    '#default_value' => !empty($body['value']) ? $body['value'] : NULL,
    '#format'=> 'ding_wysiwyg',
  );

  $form[KKB_REGISTRATION_INFOS_KEY] = array(
    '#type' => 'container',
    '#title' => t('Infos'),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="infos-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  $infos = variable_get(KKB_REGISTRATION_INFOS_KEY, []);

  if (empty($form_state['num_infos'])) {
    $info_count = count($infos);
    $form_state['num_infos'] = !empty($info_count) ? $info_count : 1;
  }

  for ($i = 0; $i < $form_state['num_infos']; $i++) {
    $form[KKB_REGISTRATION_INFOS_KEY][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Info'),
    );

    $form[KKB_REGISTRATION_INFOS_KEY][$i]['anchor'] = array(
      '#type' => 'textfield',
      '#title' => t('Anchor ID'),
      '#description' => t(
        'An anchor ID can be used to link direct to this info box, e.g. "/opretbruger#<strong>english-info</strong>" <br/>
        When you save this form, you can view the constructed anchor ID here.'
      ),
      '#default_value' => !empty($infos[$i]['anchor']) ? $infos[$i]['anchor'] : NULL,
    );

    $form[KKB_REGISTRATION_INFOS_KEY][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => !empty($infos[$i]['title']) ? $infos[$i]['title'] : NULL,
    );

    $form[KKB_REGISTRATION_INFOS_KEY][$i]['body'] = array(
      '#type' => 'text_format',
      '#title' => t('Body'),
      '#default_value' => !empty($infos[$i]['body']['value']) ? $infos[$i]['body']['value'] : NULL,
      '#format'=> 'ding_wysiwyg',
    );

    $form[KKB_REGISTRATION_INFOS_KEY][$i]['link_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Link title'),
      '#default_value' => !empty($infos[$i]['link_title']) ? $infos[$i]['link_title'] : NULL,
    );

    $form[KKB_REGISTRATION_INFOS_KEY][$i]['link_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Link URL'),
      '#default_value' => !empty($infos[$i]['link_url']) ? $infos[$i]['link_url'] : NULL,
    );
  }

  $form[KKB_REGISTRATION_INFOS_KEY]['add_name'] = array(
    '#type' => 'submit',
    '#value' => t('Add info box'),
    '#submit' => array(
      'kkb_registration_admin_add_info',
    ),
    '#decription' => t('You can delete an info-box by deleting all the data in the fields and saving.'),
    // See the examples in ajax_example.module for more details on the
    // properties of #ajax.
    '#ajax' => array(
      'callback' => 'kkb_registration_admin_add_info_callback',
      'wrapper' => 'infos-fieldset-wrapper',
    ),
  );

  $form['#submit'][] = 'kkb_registration_admin_form_submit';
  return system_settings_form($form);
}

function kkb_registration_admin_add_info($form, &$form_state) {
  $form_state['num_infos']++;
  $form_state['rebuild'] = TRUE;
}

function kkb_registration_admin_add_info_callback($form, $form_state) {
  return $form[KKB_REGISTRATION_INFOS_KEY];
}

/**
 * Submit handler for settings form.
 */
function kkb_registration_admin_form_submit(&$form, &$form_state) {
  $old_fid = variable_get('kkb_registration_image', NULL);
  $fid = !empty($form_state['values']['kkb_registration_image']) ?
    $form_state['values']['kkb_registration_image'] : NULL;

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

  $values = $form_state['values'][KKB_REGISTRATION_INFOS_KEY];
  $anchors = [];

  foreach ($values as $info_key => $info) {
    if (!is_array($info) || empty(array_filter($info))) {
      unset($values[$info_key]);

      continue;
    }

    if (!empty($info['anchor'])) {
      // By using clean_css, we make sure that the anchor is valid for URLs.
      $anchor_cleaned = drupal_clean_css_identifier($info['anchor']);

      $anchor_cleaned = strtolower($anchor_cleaned);

      // Making sure anchor IDs are unique.
      if (in_array($anchor_cleaned, $anchors)) {
        // Yes, this mean it can result in #anchorlink0000 but it's silly to
        // add a bunch of logic to increment the number for an edgecase.
        $anchor_cleaned .= '0';
      }

      $values[$info_key]['anchor'] = $anchor_cleaned;
      $anchors[] = $anchor_cleaned;
    }
  }

  // Resetting the values, after we've been unsetting elements.
  $form_state['values'][KKB_REGISTRATION_INFOS_KEY] = array_values($values);
}
