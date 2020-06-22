<?php

/**
 * @file
 * Render a teaser for the contact page.
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <a href="<?php print $link; ?>">
    <div class="kkb-contact-teaser-content">
      <h2 class="kkb-contact-teaser-header"><?php print $title; ?></h2>
      <div class="body">
        <?php print $body; ?>
      </div>
    </div>
  </a>
</div>
