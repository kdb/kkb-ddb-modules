<?php
/**
 * @file
 * kkb_brugbyen.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function kkb_brugbyen_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_base
  $overrides["field_base.field_ding_event_category.cardinality"] = -1;
  $overrides["field_base.field_ding_event_category.settings|options_list_callback"] = 'i18n_taxonomy_allowed_values';

 return $overrides;
}
