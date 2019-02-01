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
    hide($content['field_ding_help_page_related']);
    hide($content['field_ding_help_page_external']);
    ?>
  <section class="ding-help-page-main">
    <?php print render($content); ?>
  </section>

  <aside class="ding-help-page-sidebar">
    <?php print render($content['field_ding_help_page_related']); ?>
    <?php print render($content['field_ding_help_page_external']); ?>
  </aside>
</article>
