<?php

/**
 * @file
 * Template for contact page.
 */
?>
<div class="kkb-contact-page">
  <?php if (!empty($news)) : ?>
    <div class="kkb-contact-news">
      <?php print $news; ?>
    </div>
  <?php endif; ?>
  <h1><?php print $page_title; ?></h1>
  <div class="kkb-contact-section-header">
    <?php print $teasers_header; ?>
  </div>
  <form id="cludo-search-form" role="search">
      <input type="search" class="search-input" aria-label="Search" aria-describedby="autocomplete_hint" placeholder="Hvad søger du hjælp til?">
      <button type="submit" class="search-button" id="search-button">Søg</button>
  </form>

  <div id="cludo-search-results">
      <div class="cludo-r">
          <div class="cludo-c-3">
              <div class="search-filters" role="navigation"></div>
          </div>
          <div class="cludo-c-9" role="main">
              <div class="search-result-count"></div>
              <div class="search-did-you-mean"></div>
              <div class="search-results"></div>
          </div>
      </div>
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
    <h2><?php print $phone_section_title ?></h2>
    <div class="kkb-contact-section-contact-title">
      <?php print $phone_first_box_title; ?>
    </div>
    <div class="kkb-contact-section-contact-content">
      <div class="kkb-contact-phone-first kkb-contact-box">
        <?php print $phone_first_left; ?>
        <?php print $phone_first_right; ?>
      </div>
      <div class="kkb-contact-phone-second kkb-contact-box">
        <div class="kkb-contact-phone-second-number">
          <?php print $phone_second_bottom; ?>
        </div>
      </div>
    </div>
  </div>

  <a class="anchor" name="skriv"></a>
  <h2><?php print $write_section_title ?></h2>
  <div class="kkb-contact-section kkb-contact-section-boxes">
    <?php foreach ($boxes as $box) : ?>
      <?php print $box; ?>
    <?php endforeach; ?>
  </div>
</div>
