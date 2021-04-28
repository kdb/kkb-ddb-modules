<?php
  $languages = !empty($languages) ? $languages : [];
?>

<div class="kkb-registration">
  <?php foreach ($languages as $lang_key => $language): ?>
    <div class="kkb-registration__section kkb-registration__section--<?php print $lang_key; ?>" lang="<?php print $lang_key; ?>">
      <div class="kkb-registration__section-content">
        <?php if (!empty($language['title'])): ?>
        <h1>
          <?php print $language['title']; ?>
        </h1>
        <?php endif; ?>

        <?php if (!empty($language['subtitle'])): ?>
        <h2>
          <?php print $language['subtitle']; ?>
        </h2>
        <?php endif; ?>

        <?php if (!empty($language['image_render'])): ?>
        <div class="kkb-registration__image-wrapper">
          <?php print render($language['image_render']); ?>
        </div>
        <?php endif; ?>

        <?php if (!empty($language['body']['value'])): ?>
        <?php print $language['body']['value']; ?>
        <?php endif; ?>

        <?php
        $infos = !empty($language['infos']) ? $language['infos'] : [];
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
              <a href="<?php print $info['link_url']; ?>" target="<?php print $info['link_target']; ?>">
                <?php print $link_title; ?>
              </a>
            </div>
          <?php endif; ?>

        </div>
        <?php endforeach; ?>
      </div>
    </div>
  <?php endforeach; ?>

</div>
