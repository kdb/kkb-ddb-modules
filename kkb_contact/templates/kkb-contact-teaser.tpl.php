<?php

/**
 * @file
 * Render a teaser for the contact page.
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="image">
    <?php print $image; ?>
    </div>
  <h3><?php print $title; ?></h3>
  <div class="body">
    <?php print $body; ?>
  </div>
  <div class="buttons">
    <div class="more-link">
      <?php print $link; ?>
    </div>
  </div>
</div>
