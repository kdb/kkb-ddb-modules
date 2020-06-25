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

  $variables['title'] = $teaser['title'];

  if ($teaser['link']) {
    $variables['link'] = $teaser['link'];
  }
  $variables['body'] = check_plain($teaser['body']);
}

/**
 * Preprocess function for kkb_contact_box.
 */
function template_preprocess_kkb_contact_box(&$variables) {
  $box = $variables['box'];

  $variables['classes_array'][] = 'kkb-contact-teaser';
  $variables['classes_array'][] = 'kkb-contact-box';
  $variables['classes_array'][] = $variables['zebra'];

  $variables['title'] = $box['title'];

  if ($box['link']) {
    $variables['link'] = $box['link'];
  }

  if (array_key_exists('value', $box['body'])) {
    $variables['body'] = check_markup($box['body']['value'], $box['body']['format']);
  }
}

/**
 * Preprocess function for kkb_contact_news.
 */
function template_preprocess_kkb_contact_news(&$variables) {
  $news = $variables['news'];

  $variables['title'] = $news['title'];

  $variables['link'] = $news['link'];

  $variables['summary'] = $news['summary'];
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
  $node = menu_get_object();
  $language = !empty($node) ? $node->language : 'da';

  drupal_add_css(drupal_get_path('module', 'kkb_contact') . '/css/kkb_contact.block.css');
  $number = variable_get(
    'kkb_contact_page_phone_second_phone',
    KKB_CONTACT_PAGE_PHONE_SECOND_PHONE_DEFAULT
  );
  $variables['phone_header'] = variable_get('kkb_contact_page_phone_section_title_' . $language, $language === 'da' ? KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT_DA : KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT_EN);
  $variables['phone'] = l($number, 'tel:+45' . strtr($number, [' ' => '']), ['external' => TRUE]);
  $variables['opening_hours_header'] = variable_get('kkb_contact_page_phone_opening_hours_header_' . $language, $language === 'da' ? KKB_CONTACT_PAGE_PHONE_OPENING_HOURS_HEADER_DA : KKB_CONTACT_PAGE_PHONE_OPENING_HOURS_HEADER_EN);
  $variables['opening_hours'] = nl2br(variable_get('kkb_contact_page_phone_first_right_side_' . $language, $language === 'da' ? KKB_CONTACT_PAGE_PHONE_FIRST_RIGHT_SIDE_DEFAULT_DA : KKB_CONTACT_PAGE_PHONE_FIRST_RIGHT_SIDE_DEFAULT_EN));
  $variables['write'] = variable_get('kkb_contact_page_write_' . $language, $language === 'da' ? KKB_CONTACT_PAGE_WRITE_DEFAULT_DA : KKB_CONTACT_PAGE_WRITE_DEFAULT_EN);
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

