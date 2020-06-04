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

  $vars['phone_second_top'] = '<h2>' . check_plain(variable_get('kkb_contact_page_phone_second_top', KKB_CONTACT_PAGE_PHONE_SECOND_TOP_DEFAULT)) . '</h2>';
  $number = variable_get('kkb_contact_page_phone_second_phone', KKB_CONTACT_PAGE_PHONE_SECOND_PHONE_DEFAULT);
  $vars['phone_second_bottom'] .= l($number, 'tel:+45' . strtr($number, [' ' => '']), ['external' => TRUE]);

  // Write section.
  $vars['write_section_title'] = variable_get('kkb_contact_page_write_section_title', KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT);

  foreach (['first', 'second'] as $box) {
    $vars['write_' . $box . '_title'] = variable_get('kkb_contact_page_write_' . $box . '_title', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_TITLE_DEFAULT'));

    $body = variable_get('kkb_contact_page_write_' . $box . '_body',
            [
              'value' => constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_BODY_VALUE_DEFAULT'),
              'format' => constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_BODY_FORMAT_DEFAULT'),
            ]);

    $vars['write_' . $box . '_body'] = check_markup($body['value'], $body['format']);

    $link = variable_get('kkb_contact_page_write_' . $box . '_link', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_LINK_DEFAULT'));

    $vars['write_' . $box . '_link'] = '';
    if ($link) {
      $link_text = variable_get('kkb_contact_page_write_' . $box . '_link_text', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_LINK_TEXT_DEFAULT'));
      $vars['write_' . $box . '_link'] = '<div class="buttons"><div class="more-link">' . l($link_text, $link) . '</div></div>';
    }
  }

  return theme('kkb_contact_page', $vars);
}
