<?php

/**
 * @file
 * Originally a clone of Ding List Add Button template.
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <a href="#" class="trigger"><?php print $title; ?></a>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <div class="wrapper">
      <div class="inner">
        <h2><?php print t('Libraries'); ?></h2>
        <div class="close"><?php print t('Close'); ?></div>
        <?php print render($buttons); ?>
      </div>
    </div>
  </div>
</div>
