<?php
/**
 * @file
 * kkb_newsletter_paragraphs_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function kkb_newsletter_paragraphs_feature_user_default_roles() {
  $roles = array();

  // Exported role: newsletter paragraphs administrator.
  $roles['newsletter paragraphs administrator'] = array(
    'name' => 'newsletter paragraphs administrator',
    'weight' => 10,
  );

  return $roles;
}
