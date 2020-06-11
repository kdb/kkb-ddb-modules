<?php

/**
 * @file
 * Template for contact page.
 */
?>
<div class="kkb-contact-page">
  <h1><?php print $page_title; ?></h1>
  <div class="kkb-contact-section-header">
    <?php print $teasers_header; ?>
  </div>
  <div class="kkb-contact-section">
    <?php foreach ($teasers as $teaser) : ?>
    <?php print $teaser; ?>
    <?php endforeach; ?>
  </div>
  <div class="kkb-contact-section-footer">
    <?php print $teasers_footer; ?>
  </div>
  
  <a class="anchor" name="ring"></a>
  <div class="kkb-contact-section-contact">
    <div class="kkb-contact-box">
      <h2><?php print $phone_section_title ?></h2>
      <div class="kkb-contact-phone-first kkb-contact-box">
        <?php print $phone_first_left; ?>
        <?php print $phone_first_right; ?>
      </div>
    </div>
    <div class="kkb-contact-phone-second kkb-contact-box">
        <div class="kkb-contact-phone-second-number">
            <?php print $phone_second_bottom; ?>
        </div>
    </div>
  </div>
  
  <a class="anchor" name="skriv"></a>
  <h2><?php print $write_section_title ?></h2>
  <div class="kkb-contact-section">
    <div class="kkb-contact-write kkb-contact-write-first kkb-contact-box">
      <h3><?php print $write_first_title ?></h3>
      <div class="body">
        <?php print $write_first_body ?>
      </div>
      <?php print $write_first_link ?>
    </div>
    <div class="kkb-contact-write kkb-contact-write-second kkb-contact-box">
      <h3><?php print $write_second_title ?></h3>
      <div class="body">
        <?php print $write_second_body ?>
      </div>
      <?php print $write_second_link ?>
    </div>
  </div>
</div>
