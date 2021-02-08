<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
    <?php endforeach; ?>
  </div>
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
