<?php

/**
  * @file field.tpl.php
  * Override template to remove field wrapper.
  */
?>
<?php foreach ($items as $delta => $item): ?>
  <h2><?php print render($item); ?></h2>
<?php endforeach; ?>
