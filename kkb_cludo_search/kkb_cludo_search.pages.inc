<?php
/**
 * @file Cludo search result page.
 */

/**
 * Page callback english.
 */
function kkb_cludo_search_page_en($referer) {
  return _kkb_cludo_search_page('en', $referer);
}

/**
 * Page callback danish.
 */
function kkb_cludo_search_page_da($referer) {
  return _kkb_cludo_search_page('da', $referer);
}

/**
 * Page callback for cludo search page.
 *
 * @param $language -  can be either 'da' or 'en'.
 * @param $referer - can be either 'hjaelp', 'help', and 'kontakt'.
 *
 * @return string - The rendered template.
 */
function _kkb_cludo_search_page($language, $referer) {
  $vars['page_title'] = variable_get('kkb_cludo_search_page_title_' . $language,
    $language === 'da'
      ? KKB_CLUDO_SEARCH_PAGE_TITLE_DEFAULT_DA
      : KKB_CLUDO_SEARCH_PAGE_TITLE_DEFAULT_EN
  );

  $vars['language'] = $language;

  $breadcrumb = array();
  switch ($referer) {
    case 'hjaelp':
      $breadcrumb[] = l('Hjælp', $referer);
      break;
    case 'help':
      $breadcrumb[] = l('Help', $referer);
      break;
    case 'kontakt':
      $breadcrumb[] = l('Spørg biblioteket', $referer);
      break;
  }
  $breadcrumb[] = variable_get('kkb_cludo_search_page_title_' . $language,
    $language === 'da'
      ? KKB_CLUDO_SEARCH_PAGE_TITLE_DEFAULT_DA
      : KKB_CLUDO_SEARCH_PAGE_TITLE_DEFAULT_EN
  );;

  // Set Breadcrumbs
  $vars['breadcrumb'] = implode(' » ', drupal_set_breadcrumb($breadcrumb));

  return theme('kkb_cludo_search_page', $vars);
}
