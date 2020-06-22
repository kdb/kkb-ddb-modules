<?php

/**
 * @file
 * Pages for kkb_contact module.
 */

/**
 * Page callback.
 */
function kkb_contact_page() {
  $vars = [];

  $vars['page_title'] = variable_get('kkb_contact_page_title', KKB_CONTACT_PAGE_TITLE_DEFAULT);

  if ($news_article_data = variable_get('kkb_contact_page_news', KKB_CONTACT_PAGE_NEWS_DEFAULT)) {
    $news_wrapper = entity_metadata_wrapper('node', node_load($news_article_data['entity_id']));

    $news = [
      'title' => $news_wrapper->label(),
      'summary' => $news_wrapper->field_ding_news_lead->value(),
      'link' => url("node/" . $news_wrapper->getIdentifier())
    ];

    $vars['news'] = theme('kkb_contact_news', ['news' => $news]);
  }

  $header = variable_get('kkb_contact_teasers_header',
            [
              'value' => KKB_CONTACT_TEASERS_HEADER_VALUE_DEFAULT,
              'format' => KKB_CONTACT_TEASERS_HEADER_FORMAT_DEFAULT,
            ]);
  $vars['teasers_header'] = check_markup($header['value'], $header['format']);

  $teasers = variable_get('kkb_contact_teasers', []);
  $vars['teasers'] = [];
  foreach ($teasers as $teaser) {
    if ($teaser['region'] == 'enabled') {
      $vars['teasers'][] = theme('kkb_contact_teaser', ['teaser' => $teaser]);
    }
  }

  $footer = variable_get('kkb_contact_teasers_footer',
            [
              'value' => KKB_CONTACT_TEASERS_FOOTER_VALUE_DEFAULT,
              'format' => KKB_CONTACT_TEASERS_FOOTER_FORMAT_DEFAULT,
            ]);
  $vars['teasers_footer'] = check_markup($footer['value'], $footer['format']);

  // Phone section.
  $vars['phone_section_title'] = variable_get('kkb_contact_page_phone_section_title', KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT);
  $vars['phone_first_box_title'] = variable_get('kkb_contact_page_phone_first_title', KKB_CONTACT_PAGE_PHONE_FIRST_TITLE_DEFAULT);

  $left_box = variable_get('kkb_contact_page_phone_first_left_side',
              [
                'value' => KKB_CONTACT_TEASERS_FOOTER_VALUE_DEFAULT,
                'format' => KKB_CONTACT_TEASERS_FOOTER_FORMAT_DEFAULT,
              ]);

  $vars['phone_first_left'] .= '<div>' . check_markup($left_box['value'], $left_box['format']) . '</div>';
  $vars['phone_first_right'] = '<p>' . nl2br(variable_get('kkb_contact_page_phone_first_right_side', KKB_CONTACT_PAGE_PHONE_FIRST_RIGHT_SIDE_DEFAULT)) . '</p>';

  $number = variable_get('kkb_contact_page_phone_second_phone', KKB_CONTACT_PAGE_PHONE_SECOND_PHONE_DEFAULT);
  $vars['phone_second_bottom'] .= l($number, 'tel:+45' . strtr($number, [' ' => '']), ['external' => TRUE]);

  // Write section.
  $vars['write_section_title'] = variable_get('kkb_contact_page_write_section_title', KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT);

  foreach (['first', 'second'] as $box) {
    $box_content['title'] = variable_get('kkb_contact_page_write_' . $box . '_title', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_TITLE_DEFAULT'));
    $box_content['body'] = variable_get('kkb_contact_page_write_' . $box . '_body',
            [
              'value' => constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_BODY_VALUE_DEFAULT'),
              'format' => constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_BODY_FORMAT_DEFAULT'),
            ]);

    $box_content['link'] = variable_get('kkb_contact_page_write_' . $box . '_link', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_LINK_DEFAULT'));

    $vars['boxes'][] = theme('kkb_contact_box', ['box' => $box_content]);
  }

  return theme('kkb_contact_page', $vars);
}
