(function (Drupal) {
  'use strict';
  let initialized,
      html,
      useState,
      useCookies;

  function Dialog({ header, text, submitText, url }) {
    // Create a unique cookie name.
    const cookieName = `kkb_page-popup--${url.replace(/\W|\s/g, '')}`;

    const [cookies, setCookie] = useCookies([cookieName]);
    const [visible, setVisible] = useState(typeof cookies[cookieName] === 'undefined');

    /**
     * Set a "dismissed" cookie and toggle the dialog visibility.
     */
    function handleClose() {
      setVisible(!visible);
      const date = new Date();
      setCookie(cookieName, true, {
        path: '/',
        expires: new Date(date.setFullYear(date.getFullYear() + 1))
      });
    }

    if (!visible) {
      return null;
    }

    return html`
      <div className="kkb-page-dialog">
        <div className='kkb-page-dialog--close' onClick=${handleClose} />
        <div className="kkb-page-dialog--content">
          <div className="kkb-page-dialog--header">${header}</div>
          <p>${text}</p>
          <a className="kkb-page-dialog--link" href=${url} target="popup" onClick=${handleClose}>${submitText}</a>
        </div>
      </div>
    `;
  }

  function init(settings) {
    if (initialized) {
      return;
    }
    initialized = true;

    html = htm.bind(React.createElement);
    useState = React.useState;
    useCookies = ReactCookie.useCookies;


    var wrapper = document.createElement("div");
    document.body.appendChild(wrapper);

    Object.entries(settings).forEach(([key, value]) => wrapper.dataset[key] = value);

    ReactDOM.render(html`<${Dialog} ...${wrapper.dataset} />`, wrapper);
  }

  Drupal.behaviors.kkb_page = {
    attach: function (context, settings) {
      init(settings.kkb_page);
    },
  };
})(Drupal);
