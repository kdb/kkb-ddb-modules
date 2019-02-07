<?php

/**
 * @file
 * Custom node template for help pages.
 */
?>
<article class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <h1 class="page-title"><?php print $title; ?></h1>

  <?php
    // Hide fields.
    hide($content['comments']);
    hide($content['links']);
    ?>
  <?php print render($content); ?>

</article>
