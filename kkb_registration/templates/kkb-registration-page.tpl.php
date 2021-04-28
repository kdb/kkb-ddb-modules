
<div class="kkb-registration">
  <?php if (!empty($title)): ?>
    <h1>
      <?php print $title; ?>
    </h1>
  <?php endif; ?>

  <?php if (!empty($subtitle)): ?>
    <h2>
      <?php print $subtitle; ?>
    </h2>
  <?php endif; ?>

  <?php if (!empty($image)): ?>
    <div class="kkb-registration__image-wrapper">
      <?php print render($image); ?>
    </div>
  <?php endif; ?>


  <?php if (!empty($body['value'])): ?>
    <?php print $body['value']; ?>
  <?php endif; ?>

  <?php
    $infos = !empty($infos) ? $infos : [];
  ?>

  <?php foreach ($infos as $info): ?>
    <div class="kkb-registration__info"
      <?php if (!empty($info['anchor'])): ?>
        id="<?php print $info['anchor']; ?>"
      <?php endif; ?>
    >
      <?php if (!empty($info['title'])): ?>
        <h3>
          <?php print $info['title']; ?>
        </h3>
      <?php endif; ?>

      <?php if (!empty($info['body']['value'])): ?>
        <?php print $info['body']['value']; ?>
      <?php endif; ?>

      <?php if (!empty($info['link_url'])): ?>
        <?php
          // If no link title is available, we'll use the link URL.
          $link_title = !empty($info['link_title']) ? $info['link_title'] : $info['link_url'];
         ?>

        <div class="more-link">
          <a href="<?php print $info['link_url']; ?>">
            <?php print $link_title; ?>
          </a>
        </div>
      <?php endif; ?>

    </div>
  <?php endforeach; ?>
</div>
