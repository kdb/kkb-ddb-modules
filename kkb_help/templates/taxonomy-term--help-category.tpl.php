<?php

/**
 * @file
 * Custom template for help category terms.
 */
?>
<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">

  <h1 class="page-title"><?php print $term_name; ?></h1>

  <div class="content">
    <?php print render($content); ?>
  </div>

</div>
