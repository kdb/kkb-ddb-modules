<?php

/**
 * @file
 * Template for contact page.
 */
?>
<div class="breadcrumb cludo-breadcrumb"><?php print $breadcrumb; ?></div>

<div class="kkb-cludo-search-page">
  <h1><?php print $page_title; ?></h1>
  <?php if($language === 'da'): ?>
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
  <?php else: ?>
    <form id="cludo-search-form-english" role="search">
      <input type="search" class="search-input" aria-label="Search" aria-describedby="autocomplete_hint" placeholder="What are you looking for help with?">
      <button type="submit" class="search-button" id="search-button">Search</button>
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
  <?php endif; ?>
</div>
