<?php

/**
  * @file field.tpl.php
  * Override template to remove field wrapper.
  */
?>
<?php foreach ($items as $delta => $item): ?>
  <?php print render($item); ?>
<?php endforeach; ?>
