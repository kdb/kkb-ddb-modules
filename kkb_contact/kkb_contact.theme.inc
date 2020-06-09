<?php

/**
 * @file
 * Theme functions for kkb_contact.
 */

/**
 * Preprocess function for kkb_contact_teaser.
 */
function template_preprocess_kkb_contact_teaser(&$variables) {
  $teaser = $variables['teaser'];

  $variables['classes_array'][] = 'kkb-contact-teaser';
  $variables['classes_array'][] = 'kkb-contact-box';
  $variables['classes_array'][] = $variables['zebra'];

  if ($teaser['link']) {
    $variables['title'] = l($teaser['title'], $teaser['link']);
    // Hide the read more link and the image from screen readers. The title link
    // is better for them.
    $attributes = ['aria-hidden' => 'true'];
    $variables['link'] = l($teaser['link_text'] ? $teaser['link_text'] : t('Read more'), $teaser['link'], ['attributes' => $attributes]);
    $variables['image'] = l($variables['image'], $teaser['link'], ['html' => TRUE, 'attributes' => $attributes]);
  }
  else {
    $variables['title'] = $teaser['title'];
    $variables['link'] = '';
  }
  $variables['body'] = check_plain($teaser['body']);
}

/**
 * Preprocess function for kkb_contact_page.
 */
function template_preprocess_kkb_contact_page(&$variables) {
  drupal_add_css(drupal_get_path('module', 'kkb_contact') . '/css/kkb_contact.css');
}

/**
 * Preprocess function for kkb_contact_block.
 */
function template_preprocess_kkb_contact_block(&$variables) {
  drupal_add_css(drupal_get_path('module', 'kkb_contact') . '/css/kkb_contact.block.css');
  $number = variable_get(
    'kkb_contact_page_phone_second_phone',
    KKB_CONTACT_PAGE_PHONE_SECOND_PHONE_DEFAULT
  );
  $variables['phone'] = l($number, 'tel:+45' . strtr($number, [' ' => '']), ['external' => TRUE]);
  $variables['opening_hours'] = nl2br(variable_get('kkb_contact_page_phone_first_right_side', KKB_CONTACT_PAGE_PHONE_FIRST_RIGHT_SIDE_DEFAULT));
}

/**
 * Theme function for the settings form teasers.
 */
function theme_kkb_contact_settings_teasers(&$variables) {
  $form = $variables['form'];

  $header = ['', t('Body'), t('Weight'), t('Status'), t('Operations')];
  $region_rows = [
    'enabled' => [],
    'disabled' => [],
  ];

  foreach (element_children($form) as $key) {
    $region = $form[$key]['region']['#default_value'];
    $form[$key]['region']['#attributes']['class'] = [
      'kkb-contact-settings-element-status',
      'kkb-contact-settings-element-status-' . $region,
    ];
    $form[$key]['weight']['#attributes']['class'] = [
      'kkb-contact-settings-element-weight',
      'kkb-contact-settings-element-weight-' . $region,
    ];
    // Pre-render elements we want to remove from the main part.
    $weight = drupal_render($form[$key]['weight']);
    $region_widget = drupal_render($form[$key]['region']);
    $actions = drupal_render($form[$key]['delete']);
    $body = drupal_render($form[$key]['body']);
    $region_rows[$region][] = [
      'data' => [
        '<div class="kkb-contact-teaser-details">' . drupal_render($form[$key]) . '</div>',
        $body,
        $weight,
        $region_widget,
        $actions,
      ],
      'class' => ['draggable'],
    ];
  }

  $sections = [
    'enabled' => t('Enabled'),
    'disabled' => t('Disabled'),
  ];

  foreach ($sections as $key => $name) {
    $cell = [
      'data' => "<strong>" . $name . "</strong>",
      'colspan' => 4,
    ];
    $row = [
      'data' => [$cell],
      'class' => ['js-kkb-contact-settings-status', 'js-kkb-contact-settings-status-' . $key],
    ];
    $section_rows[$key] = [$row];
  }

  $rows = array_merge(
    $section_rows['enabled'],
    $region_rows['enabled'],
    $section_rows['disabled'],
    $region_rows['disabled']
  );

  $table = [
    'header' => $header,
    'rows' => $rows,
    'attributes' => ['id' => 'kkb-contact-settings-admin-sort'],
    'sticky' => TRUE,
  ];
  $output = theme('table', $table);

  // Render remaining elements.
  $output .= drupal_render_children($form);

  foreach (['enabled', 'disabled'] as $region) {
    drupal_add_tabledrag(
      'kkb-contact-settings-admin-sort',
      'match', 'sibling',
      'kkb-contact-settings-element-status',
      'kkb-contact-settings-element-status-' . $region
    );
    drupal_add_tabledrag(
      'kkb-contact-settings-admin-sort',
      'order',
      'sibling',
      'kkb-contact-settings-element-weight',
      'kkb-contact-settings-element-weight-' . $region);
  }

  return $output;

}
