<?php

/**
  * @file field.tpl.php
  * Override template to remove field wrapper.
  */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <ol class="step-items js-step-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <li class="step-item"><?php print render($item); ?></li>
    <?php endforeach; ?>
  </ol>
</div>
