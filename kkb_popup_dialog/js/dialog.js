(function (Drupal) {
  'use strict';
  let initialized,
      html,
      useState,
      useEffect,
      useRef,
      useCookies;

  function Dialog() {
    const [settings, setSettings] = useState(null);
    const [cookies, setCookie] = useCookies(null);
    const link = useRef(null);

    /**
     * Get dialog content.
     */
    useEffect(() => {
      const endpoint = `${window.location.origin}/kkb_popup_dialog/ajax/display?pathname=${encodeURIComponent(window.location.pathname)}`;
      fetch(endpoint , {
        cache: "no-store"
      })
      .then(response => response.json())
      .then((data )=> data.url && setSettings(data));
    }, []);

    if (!settings) {
      return null;
    }


    const { wait, header, url, text, submitText, cookieName } = settings;

    /**
     * Do not display if the user has already used or dismissed the dialog.
     */
    if (cookies[cookieName]) {
      return null;
    }

    /**
     * Set a "dismissed" cookie.
     */
    function handleClose() {
      const date = new Date();
      setCookie(cookieName, true, {
        path: '/',
        expires: new Date(date.setFullYear(date.getFullYear() + 1))
      });
    }

    function handleSubmit() {
      handleClose();
      if (link.current) {
        link.current.click();
      }
    }

    const style = {
      animation: `1s ease-out ${parseInt(wait, 10)}s 1 slideInFromBottom both`
    }

    return html`
      <div className="kkb-popup-dialog" style=${style}>
        <button className='kkb-popup-dialog--close' onClick=${handleClose} />
        <div className="kkb-popup-dialog--content">
          <h1 className="kkb-popup-dialog--header">${header}</h1>
          <p>${text}</p>
          <button className="kkb-popup-dialog--link" onClick=${handleSubmit}>${submitText}</button>
          <a ref=${link} href=${url} className="kkb-popup-dialog--link-hidden" target="popup" />
        </div>
      </div>
    `;
  }

  function init() {
    if (initialized) {
      return;
    }
    initialized = true;

    html = htm.bind(React.createElement);
    useState = React.useState;
    useEffect = React.useEffect;
    useRef = React.useRef;
    useCookies = ReactCookie.useCookies;


    var wrapper = document.createElement("div");
    document.body.appendChild(wrapper);

    ReactDOM.render(html`<${Dialog} />`, wrapper);
  }

  Drupal.behaviors.kkb_popup_dialog = {
    attach: function () {
      init();
    },
  };
})(Drupal);
