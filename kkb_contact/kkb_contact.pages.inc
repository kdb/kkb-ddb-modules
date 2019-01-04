<?php

/**
 * @file
 * Pages for kkb_contact module.
 */

/**
 * Page callback.
 */
function kkb_contact_page() {
  $content = '<div class="kkb-contact-page">';
  $content .= '<h1>' . variable_get('kkb_contact_page_title', KKB_CONTACT_PAGE_TITLE_DEFAULT) . '</h1>';

  drupal_add_css(drupal_get_path('module', 'kkb_contact') . '/css/kkb_contact.css');

  $header = variable_get('kkb_contact_teasers_header',
            [
              'value' => KKB_CONTACT_TEASERS_HEADER_VALUE_DEFAULT,
              'format' => KKB_CONTACT_TEASERS_HEADER_FORMAT_DEFAULT,
            ]);

  $content .= '<div class="kkb-contact-section-header">';
  $content .= check_markup($header['value'], $header['format']);
  $content .= '</div>';

  // Teaser section.
  $teasers = variable_get('kkb_contact_teasers', []);
  $content .= '<div class="kkb-contact-section">';

  foreach ($teasers as $teaser) {
    if ($teaser['region'] == 'enabled') {
      $content .= theme('kkb_contact_teaser', ['teaser' => $teaser]);
    }
  }
  $content .= '</div>';

  $footer = variable_get('kkb_contact_teasers_footer',
            [
              'value' => KKB_CONTACT_TEASERS_FOOTER_VALUE_DEFAULT,
              'format' => KKB_CONTACT_TEASERS_FOOTER_FORMAT_DEFAULT,
            ]);

  $content .= '<div class="kkb-contact-section-footer">';
  $content .= check_markup($footer['value'], $footer['format']);
  $content .= '</div>';

  // Phone section.
  $content .= '<a class="anchor" name="ring"></a>';
  $content .= '<h2>' . variable_get('kkb_contact_page_phone_section_title', KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT) . '</h2>';
  $content .= '<div class="kkb-contact-section"><div class="kkb-contact-phone-first kkb-contact-box">';

  $content .= '<h3>' . variable_get('kkb_contact_page_phone_first_title', KKB_CONTACT_PAGE_PHONE_FIRST_TITLE_DEFAULT) . '</h3>';

  $left_box = variable_get('kkb_contact_page_phone_first_left_side',
              [
                'value' => KKB_CONTACT_TEASERS_FOOTER_VALUE_DEFAULT,
                'format' => KKB_CONTACT_TEASERS_FOOTER_FORMAT_DEFAULT,
              ]);

  $content .= '<div>';
  $content .= check_markup($left_box['value'], $left_box['format']);
  $content .= '</div>';

  $content .= '<p>' . nl2br(variable_get('kkb_contact_page_phone_first_right_side', KKB_CONTACT_PAGE_PHONE_FIRST_RIGHT_SIDE_DEFAULT)) . '</p>';

  $content .= '</div><div class="kkb-contact-phone-second kkb-contact-box">';

  $content .= '<p>' . check_plain(variable_get('kkb_contact_page_phone_second_top', KKB_CONTACT_PAGE_PHONE_SECOND_TOP_DEFAULT)) . '</p>';
  $number = variable_get('kkb_contact_page_phone_second_phone', KKB_CONTACT_PAGE_PHONE_SECOND_PHONE_DEFAULT);
  $content .= l($number, 'tel:+45' . strtr($number, [' ' => '']), ['external' => TRUE]);

  $content .= '</div></div>';

  // Write section.
  $content .= '<a class="anchor" name="skriv"></a>';
  $content .= '<h2>' . variable_get('kkb_contact_page_write_section_title', KKB_CONTACT_PAGE_PHONE_SECTION_TITLE_DEFAULT) . '</h2>';
  $content .= '<div class="kkb-contact-section">';

  foreach (['first', 'second'] as $box) {
    $content .= '<div class="kkb-contact-write kkb-contact-write-' . $box . ' kkb-contact-box">';
    $content .= '<h3>' . variable_get('kkb_contact_page_write_' . $box . '_title', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_TITLE_DEFAULT')) . '</h3>';

    $body = variable_get('kkb_contact_page_write_' . $box . '_body',
            [
              'value' => constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_BODY_VALUE_DEFAULT'),
              'format' => constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_BODY_FORMAT_DEFAULT'),
            ]);

    $content .= '<div class="body">' . check_markup($body['value'], $body['format']) . '</div>';

    $link = variable_get('kkb_contact_page_write_' . $box . '_link', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_LINK_DEFAULT'));
    $link_text = variable_get('kkb_contact_page_write_' . $box . '_link_text', constant('KKB_CONTACT_PAGE_WRITE_' . strtoupper($box) . '_LINK_TEXT_DEFAULT'));

    if ($link) {
      $content .= '<div class="buttons"><div class="more-link">' . l($link_text, $link) . '</div></div>';
    }

    $content .= '</div>';
  }

  $content .= '</div>';
  $content .= '</div>';

  return $content;
}
