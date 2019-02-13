<?php

/**
 * @file
 * Custom node template for help pages.
 */
?>
<article class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="ding-help-page-content">
    <section class="ding-help-page-main">
      <?php if ($page): ?>
        <h1 class="page-title"><?php print $title; ?></h1>
      <?php else: ?>
        <h3><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
      <?php endif; ?>

    <?php
      // Hide fields.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_ding_help_page_related']);
      hide($content['field_ding_help_page_external']);
      hide($content['field_ding_help_page_files']);
      ?>
      <?php print render($content); ?>
    </section>

    <aside class="ding-help-page-sidebar">
      <?php print render($content['field_ding_help_page_files']); ?>
      <?php print render($content['field_ding_help_page_related']); ?>
      <?php print render($content['field_ding_help_page_external']); ?>
    </aside>
  </div>
</article>
