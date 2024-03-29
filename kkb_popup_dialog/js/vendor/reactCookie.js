(function (global, factory) {
	typeof exports === 'object' && typeof module !== 'undefined' ? module.exports = factory(require('universal-cookie'), require('react')) :
	typeof define === 'function' && define.amd ? define(['universal-cookie', 'react'], factory) :
	(global.ReactCookie = factory(global.UniversalCookie,global.React));
}(this, (function (universalCookie,_react) { 'use strict';

	universalCookie = universalCookie && universalCookie.hasOwnProperty('default') ? universalCookie['default'] : universalCookie;
	_react = _react && _react.hasOwnProperty('default') ? _react['default'] : _react;

	function unwrapExports (x) {
		return x && x.__esModule && Object.prototype.hasOwnProperty.call(x, 'default') ? x['default'] : x;
	}

	function createCommonjsModule(fn, module) {
		return module = { exports: {} }, fn(module, module.exports), module.exports;
	}

	var Cookies = createCommonjsModule(function (module, exports) {

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	exports.default = void 0;

	var _universalCookie = _interopRequireDefault(universalCookie);

	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

	var _default = _universalCookie.default;
	exports.default = _default;
	module.exports = exports.default;
	});

	unwrapExports(Cookies);

	var CookiesContext_1 = createCommonjsModule(function (module, exports) {

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	exports.default = exports.Consumer = exports.Provider = void 0;

	var React = _interopRequireWildcard(_react);

	var _Cookies = _interopRequireDefault(Cookies);

	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

	function _interopRequireWildcard(obj) { if (obj && obj.__esModule) { return obj; } else { var newObj = {}; if (obj != null) { for (var key in obj) { if (Object.prototype.hasOwnProperty.call(obj, key)) { var desc = Object.defineProperty && Object.getOwnPropertyDescriptor ? Object.getOwnPropertyDescriptor(obj, key) : {}; if (desc.get || desc.set) { Object.defineProperty(newObj, key, desc); } else { newObj[key] = obj[key]; } } } } newObj.default = obj; return newObj; } }

	var CookiesContext = React.createContext(new _Cookies.default());
	var Provider = CookiesContext.Provider,
	    Consumer = CookiesContext.Consumer;
	exports.Consumer = Consumer;
	exports.Provider = Provider;
	var _default = CookiesContext;
	exports.default = _default;
	});

	unwrapExports(CookiesContext_1);
	var CookiesContext_2 = CookiesContext_1.Consumer;
	var CookiesContext_3 = CookiesContext_1.Provider;

	var CookiesProvider_1 = createCommonjsModule(function (module, exports) {

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	exports.default = void 0;

	var React = _interopRequireWildcard(_react);

	var _universalCookie = _interopRequireDefault(universalCookie);



	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

	function _interopRequireWildcard(obj) { if (obj && obj.__esModule) { return obj; } else { var newObj = {}; if (obj != null) { for (var key in obj) { if (Object.prototype.hasOwnProperty.call(obj, key)) { var desc = Object.defineProperty && Object.getOwnPropertyDescriptor ? Object.getOwnPropertyDescriptor(obj, key) : {}; if (desc.get || desc.set) { Object.defineProperty(newObj, key, desc); } else { newObj[key] = obj[key]; } } } } newObj.default = obj; return newObj; } }

	var __extends = function () {
	  var _extendStatics = function extendStatics(d, b) {
	    _extendStatics = Object.setPrototypeOf || {
	      __proto__: []
	    } instanceof Array && function (d, b) {
	      d.__proto__ = b;
	    } || function (d, b) {
	      for (var p in b) {
	        if (b.hasOwnProperty(p)) d[p] = b[p];
	      }
	    };

	    return _extendStatics(d, b);
	  };

	  return function (d, b) {
	    _extendStatics(d, b);

	    function __() {
	      this.constructor = d;
	    }

	    d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
	  };
	}();

	var CookiesProvider =
	/** @class */
	function (_super) {
	  __extends(CookiesProvider, _super);

	  function CookiesProvider(props) {
	    var _this = _super.call(this, props) || this;

	    if (props.cookies) {
	      _this.cookies = props.cookies;
	    } else {
	      _this.cookies = new _universalCookie.default();
	    }

	    return _this;
	  }

	  CookiesProvider.prototype.render = function () {
	    return React.createElement(CookiesContext_1.Provider, {
	      value: this.cookies
	    }, this.props.children);
	  };

	  return CookiesProvider;
	}(React.Component);

	var _default = CookiesProvider;
	exports.default = _default;
	module.exports = exports.default;
	});

	unwrapExports(CookiesProvider_1);

	var reactIs_production_min = createCommonjsModule(function (module, exports) {
	Object.defineProperty(exports,"__esModule",{value:!0});
	var b="function"===typeof Symbol&&Symbol.for,c=b?Symbol.for("react.element"):60103,d=b?Symbol.for("react.portal"):60106,e=b?Symbol.for("react.fragment"):60107,f=b?Symbol.for("react.strict_mode"):60108,g=b?Symbol.for("react.profiler"):60114,h=b?Symbol.for("react.provider"):60109,k=b?Symbol.for("react.context"):60110,l=b?Symbol.for("react.async_mode"):60111,m=b?Symbol.for("react.concurrent_mode"):60111,n=b?Symbol.for("react.forward_ref"):60112,p=b?Symbol.for("react.suspense"):60113,q=b?Symbol.for("react.memo"):
	60115,r=b?Symbol.for("react.lazy"):60116;function t(a){if("object"===typeof a&&null!==a){var u=a.$$typeof;switch(u){case c:switch(a=a.type,a){case l:case m:case e:case g:case f:case p:return a;default:switch(a=a&&a.$$typeof,a){case k:case n:case h:return a;default:return u}}case r:case q:case d:return u}}}function v(a){return t(a)===m}exports.typeOf=t;exports.AsyncMode=l;exports.ConcurrentMode=m;exports.ContextConsumer=k;exports.ContextProvider=h;exports.Element=c;exports.ForwardRef=n;
	exports.Fragment=e;exports.Lazy=r;exports.Memo=q;exports.Portal=d;exports.Profiler=g;exports.StrictMode=f;exports.Suspense=p;exports.isValidElementType=function(a){return "string"===typeof a||"function"===typeof a||a===e||a===m||a===g||a===f||a===p||"object"===typeof a&&null!==a&&(a.$$typeof===r||a.$$typeof===q||a.$$typeof===h||a.$$typeof===k||a.$$typeof===n)};exports.isAsyncMode=function(a){return v(a)||t(a)===l};exports.isConcurrentMode=v;exports.isContextConsumer=function(a){return t(a)===k};
	exports.isContextProvider=function(a){return t(a)===h};exports.isElement=function(a){return "object"===typeof a&&null!==a&&a.$$typeof===c};exports.isForwardRef=function(a){return t(a)===n};exports.isFragment=function(a){return t(a)===e};exports.isLazy=function(a){return t(a)===r};exports.isMemo=function(a){return t(a)===q};exports.isPortal=function(a){return t(a)===d};exports.isProfiler=function(a){return t(a)===g};exports.isStrictMode=function(a){return t(a)===f};
	exports.isSuspense=function(a){return t(a)===p};
	});

	unwrapExports(reactIs_production_min);
	var reactIs_production_min_1 = reactIs_production_min.typeOf;
	var reactIs_production_min_2 = reactIs_production_min.AsyncMode;
	var reactIs_production_min_3 = reactIs_production_min.ConcurrentMode;
	var reactIs_production_min_4 = reactIs_production_min.ContextConsumer;
	var reactIs_production_min_5 = reactIs_production_min.ContextProvider;
	var reactIs_production_min_6 = reactIs_production_min.Element;
	var reactIs_production_min_7 = reactIs_production_min.ForwardRef;
	var reactIs_production_min_8 = reactIs_production_min.Fragment;
	var reactIs_production_min_9 = reactIs_production_min.Lazy;
	var reactIs_production_min_10 = reactIs_production_min.Memo;
	var reactIs_production_min_11 = reactIs_production_min.Portal;
	var reactIs_production_min_12 = reactIs_production_min.Profiler;
	var reactIs_production_min_13 = reactIs_production_min.StrictMode;
	var reactIs_production_min_14 = reactIs_production_min.Suspense;
	var reactIs_production_min_15 = reactIs_production_min.isValidElementType;
	var reactIs_production_min_16 = reactIs_production_min.isAsyncMode;
	var reactIs_production_min_17 = reactIs_production_min.isConcurrentMode;
	var reactIs_production_min_18 = reactIs_production_min.isContextConsumer;
	var reactIs_production_min_19 = reactIs_production_min.isContextProvider;
	var reactIs_production_min_20 = reactIs_production_min.isElement;
	var reactIs_production_min_21 = reactIs_production_min.isForwardRef;
	var reactIs_production_min_22 = reactIs_production_min.isFragment;
	var reactIs_production_min_23 = reactIs_production_min.isLazy;
	var reactIs_production_min_24 = reactIs_production_min.isMemo;
	var reactIs_production_min_25 = reactIs_production_min.isPortal;
	var reactIs_production_min_26 = reactIs_production_min.isProfiler;
	var reactIs_production_min_27 = reactIs_production_min.isStrictMode;
	var reactIs_production_min_28 = reactIs_production_min.isSuspense;

	var reactIs_development = createCommonjsModule(function (module, exports) {



	{
	  (function() {

	Object.defineProperty(exports, '__esModule', { value: true });

	// The Symbol used to tag the ReactElement-like types. If there is no native Symbol
	// nor polyfill, then a plain number is used for performance.
	var hasSymbol = typeof Symbol === 'function' && Symbol.for;

	var REACT_ELEMENT_TYPE = hasSymbol ? Symbol.for('react.element') : 0xeac7;
	var REACT_PORTAL_TYPE = hasSymbol ? Symbol.for('react.portal') : 0xeaca;
	var REACT_FRAGMENT_TYPE = hasSymbol ? Symbol.for('react.fragment') : 0xeacb;
	var REACT_STRICT_MODE_TYPE = hasSymbol ? Symbol.for('react.strict_mode') : 0xeacc;
	var REACT_PROFILER_TYPE = hasSymbol ? Symbol.for('react.profiler') : 0xead2;
	var REACT_PROVIDER_TYPE = hasSymbol ? Symbol.for('react.provider') : 0xeacd;
	var REACT_CONTEXT_TYPE = hasSymbol ? Symbol.for('react.context') : 0xeace;
	var REACT_ASYNC_MODE_TYPE = hasSymbol ? Symbol.for('react.async_mode') : 0xeacf;
	var REACT_CONCURRENT_MODE_TYPE = hasSymbol ? Symbol.for('react.concurrent_mode') : 0xeacf;
	var REACT_FORWARD_REF_TYPE = hasSymbol ? Symbol.for('react.forward_ref') : 0xead0;
	var REACT_SUSPENSE_TYPE = hasSymbol ? Symbol.for('react.suspense') : 0xead1;
	var REACT_MEMO_TYPE = hasSymbol ? Symbol.for('react.memo') : 0xead3;
	var REACT_LAZY_TYPE = hasSymbol ? Symbol.for('react.lazy') : 0xead4;

	function isValidElementType(type) {
	  return typeof type === 'string' || typeof type === 'function' ||
	  // Note: its typeof might be other than 'symbol' or 'number' if it's a polyfill.
	  type === REACT_FRAGMENT_TYPE || type === REACT_CONCURRENT_MODE_TYPE || type === REACT_PROFILER_TYPE || type === REACT_STRICT_MODE_TYPE || type === REACT_SUSPENSE_TYPE || typeof type === 'object' && type !== null && (type.$$typeof === REACT_LAZY_TYPE || type.$$typeof === REACT_MEMO_TYPE || type.$$typeof === REACT_PROVIDER_TYPE || type.$$typeof === REACT_CONTEXT_TYPE || type.$$typeof === REACT_FORWARD_REF_TYPE);
	}

	/**
	 * Forked from fbjs/warning:
	 * https://github.com/facebook/fbjs/blob/e66ba20ad5be433eb54423f2b097d829324d9de6/packages/fbjs/src/__forks__/warning.js
	 *
	 * Only change is we use console.warn instead of console.error,
	 * and do nothing when 'console' is not supported.
	 * This really simplifies the code.
	 * ---
	 * Similar to invariant but only logs a warning if the condition is not met.
	 * This can be used to log issues in development environments in critical
	 * paths. Removing the logging code for production environments will keep the
	 * same logic and follow the same code paths.
	 */

	var lowPriorityWarning = function () {};

	{
	  var printWarning = function (format) {
	    for (var _len = arguments.length, args = Array(_len > 1 ? _len - 1 : 0), _key = 1; _key < _len; _key++) {
	      args[_key - 1] = arguments[_key];
	    }

	    var argIndex = 0;
	    var message = 'Warning: ' + format.replace(/%s/g, function () {
	      return args[argIndex++];
	    });
	    if (typeof console !== 'undefined') {
	      console.warn(message);
	    }
	    try {
	      // --- Welcome to debugging React ---
	      // This error was thrown as a convenience so that you can use this stack
	      // to find the callsite that caused this warning to fire.
	      throw new Error(message);
	    } catch (x) {}
	  };

	  lowPriorityWarning = function (condition, format) {
	    if (format === undefined) {
	      throw new Error('`lowPriorityWarning(condition, format, ...args)` requires a warning ' + 'message argument');
	    }
	    if (!condition) {
	      for (var _len2 = arguments.length, args = Array(_len2 > 2 ? _len2 - 2 : 0), _key2 = 2; _key2 < _len2; _key2++) {
	        args[_key2 - 2] = arguments[_key2];
	      }

	      printWarning.apply(undefined, [format].concat(args));
	    }
	  };
	}

	var lowPriorityWarning$1 = lowPriorityWarning;

	function typeOf(object) {
	  if (typeof object === 'object' && object !== null) {
	    var $$typeof = object.$$typeof;
	    switch ($$typeof) {
	      case REACT_ELEMENT_TYPE:
	        var type = object.type;

	        switch (type) {
	          case REACT_ASYNC_MODE_TYPE:
	          case REACT_CONCURRENT_MODE_TYPE:
	          case REACT_FRAGMENT_TYPE:
	          case REACT_PROFILER_TYPE:
	          case REACT_STRICT_MODE_TYPE:
	          case REACT_SUSPENSE_TYPE:
	            return type;
	          default:
	            var $$typeofType = type && type.$$typeof;

	            switch ($$typeofType) {
	              case REACT_CONTEXT_TYPE:
	              case REACT_FORWARD_REF_TYPE:
	              case REACT_PROVIDER_TYPE:
	                return $$typeofType;
	              default:
	                return $$typeof;
	            }
	        }
	      case REACT_LAZY_TYPE:
	      case REACT_MEMO_TYPE:
	      case REACT_PORTAL_TYPE:
	        return $$typeof;
	    }
	  }

	  return undefined;
	}

	// AsyncMode is deprecated along with isAsyncMode
	var AsyncMode = REACT_ASYNC_MODE_TYPE;
	var ConcurrentMode = REACT_CONCURRENT_MODE_TYPE;
	var ContextConsumer = REACT_CONTEXT_TYPE;
	var ContextProvider = REACT_PROVIDER_TYPE;
	var Element = REACT_ELEMENT_TYPE;
	var ForwardRef = REACT_FORWARD_REF_TYPE;
	var Fragment = REACT_FRAGMENT_TYPE;
	var Lazy = REACT_LAZY_TYPE;
	var Memo = REACT_MEMO_TYPE;
	var Portal = REACT_PORTAL_TYPE;
	var Profiler = REACT_PROFILER_TYPE;
	var StrictMode = REACT_STRICT_MODE_TYPE;
	var Suspense = REACT_SUSPENSE_TYPE;

	var hasWarnedAboutDeprecatedIsAsyncMode = false;

	// AsyncMode should be deprecated
	function isAsyncMode(object) {
	  {
	    if (!hasWarnedAboutDeprecatedIsAsyncMode) {
	      hasWarnedAboutDeprecatedIsAsyncMode = true;
	      lowPriorityWarning$1(false, 'The ReactIs.isAsyncMode() alias has been deprecated, ' + 'and will be removed in React 17+. Update your code to use ' + 'ReactIs.isConcurrentMode() instead. It has the exact same API.');
	    }
	  }
	  return isConcurrentMode(object) || typeOf(object) === REACT_ASYNC_MODE_TYPE;
	}
	function isConcurrentMode(object) {
	  return typeOf(object) === REACT_CONCURRENT_MODE_TYPE;
	}
	function isContextConsumer(object) {
	  return typeOf(object) === REACT_CONTEXT_TYPE;
	}
	function isContextProvider(object) {
	  return typeOf(object) === REACT_PROVIDER_TYPE;
	}
	function isElement(object) {
	  return typeof object === 'object' && object !== null && object.$$typeof === REACT_ELEMENT_TYPE;
	}
	function isForwardRef(object) {
	  return typeOf(object) === REACT_FORWARD_REF_TYPE;
	}
	function isFragment(object) {
	  return typeOf(object) === REACT_FRAGMENT_TYPE;
	}
	function isLazy(object) {
	  return typeOf(object) === REACT_LAZY_TYPE;
	}
	function isMemo(object) {
	  return typeOf(object) === REACT_MEMO_TYPE;
	}
	function isPortal(object) {
	  return typeOf(object) === REACT_PORTAL_TYPE;
	}
	function isProfiler(object) {
	  return typeOf(object) === REACT_PROFILER_TYPE;
	}
	function isStrictMode(object) {
	  return typeOf(object) === REACT_STRICT_MODE_TYPE;
	}
	function isSuspense(object) {
	  return typeOf(object) === REACT_SUSPENSE_TYPE;
	}

	exports.typeOf = typeOf;
	exports.AsyncMode = AsyncMode;
	exports.ConcurrentMode = ConcurrentMode;
	exports.ContextConsumer = ContextConsumer;
	exports.ContextProvider = ContextProvider;
	exports.Element = Element;
	exports.ForwardRef = ForwardRef;
	exports.Fragment = Fragment;
	exports.Lazy = Lazy;
	exports.Memo = Memo;
	exports.Portal = Portal;
	exports.Profiler = Profiler;
	exports.StrictMode = StrictMode;
	exports.Suspense = Suspense;
	exports.isValidElementType = isValidElementType;
	exports.isAsyncMode = isAsyncMode;
	exports.isConcurrentMode = isConcurrentMode;
	exports.isContextConsumer = isContextConsumer;
	exports.isContextProvider = isContextProvider;
	exports.isElement = isElement;
	exports.isForwardRef = isForwardRef;
	exports.isFragment = isFragment;
	exports.isLazy = isLazy;
	exports.isMemo = isMemo;
	exports.isPortal = isPortal;
	exports.isProfiler = isProfiler;
	exports.isStrictMode = isStrictMode;
	exports.isSuspense = isSuspense;
	  })();
	}
	});

	unwrapExports(reactIs_development);
	var reactIs_development_1 = reactIs_development.typeOf;
	var reactIs_development_2 = reactIs_development.AsyncMode;
	var reactIs_development_3 = reactIs_development.ConcurrentMode;
	var reactIs_development_4 = reactIs_development.ContextConsumer;
	var reactIs_development_5 = reactIs_development.ContextProvider;
	var reactIs_development_6 = reactIs_development.Element;
	var reactIs_development_7 = reactIs_development.ForwardRef;
	var reactIs_development_8 = reactIs_development.Fragment;
	var reactIs_development_9 = reactIs_development.Lazy;
	var reactIs_development_10 = reactIs_development.Memo;
	var reactIs_development_11 = reactIs_development.Portal;
	var reactIs_development_12 = reactIs_development.Profiler;
	var reactIs_development_13 = reactIs_development.StrictMode;
	var reactIs_development_14 = reactIs_development.Suspense;
	var reactIs_development_15 = reactIs_development.isValidElementType;
	var reactIs_development_16 = reactIs_development.isAsyncMode;
	var reactIs_development_17 = reactIs_development.isConcurrentMode;
	var reactIs_development_18 = reactIs_development.isContextConsumer;
	var reactIs_development_19 = reactIs_development.isContextProvider;
	var reactIs_development_20 = reactIs_development.isElement;
	var reactIs_development_21 = reactIs_development.isForwardRef;
	var reactIs_development_22 = reactIs_development.isFragment;
	var reactIs_development_23 = reactIs_development.isLazy;
	var reactIs_development_24 = reactIs_development.isMemo;
	var reactIs_development_25 = reactIs_development.isPortal;
	var reactIs_development_26 = reactIs_development.isProfiler;
	var reactIs_development_27 = reactIs_development.isStrictMode;
	var reactIs_development_28 = reactIs_development.isSuspense;

	var reactIs = createCommonjsModule(function (module) {

	{
	  module.exports = reactIs_development;
	}
	});

	/**
	 * Copyright 2015, Yahoo! Inc.
	 * Copyrights licensed under the New BSD License. See the accompanying LICENSE file for terms.
	 */

	var REACT_STATICS = {
	    childContextTypes: true,
	    contextType: true,
	    contextTypes: true,
	    defaultProps: true,
	    displayName: true,
	    getDefaultProps: true,
	    getDerivedStateFromError: true,
	    getDerivedStateFromProps: true,
	    mixins: true,
	    propTypes: true,
	    type: true
	};

	var KNOWN_STATICS = {
	    name: true,
	    length: true,
	    prototype: true,
	    caller: true,
	    callee: true,
	    arguments: true,
	    arity: true
	};

	var FORWARD_REF_STATICS = {
	    '$$typeof': true,
	    render: true,
	    defaultProps: true,
	    displayName: true,
	    propTypes: true
	};

	var MEMO_STATICS = {
	    '$$typeof': true,
	    compare: true,
	    defaultProps: true,
	    displayName: true,
	    propTypes: true,
	    type: true
	};

	var TYPE_STATICS = {};
	TYPE_STATICS[reactIs.ForwardRef] = FORWARD_REF_STATICS;

	function getStatics(component) {
	    if (reactIs.isMemo(component)) {
	        return MEMO_STATICS;
	    }
	    return TYPE_STATICS[component['$$typeof']] || REACT_STATICS;
	}

	var defineProperty = Object.defineProperty;
	var getOwnPropertyNames = Object.getOwnPropertyNames;
	var getOwnPropertySymbols = Object.getOwnPropertySymbols;
	var getOwnPropertyDescriptor = Object.getOwnPropertyDescriptor;
	var getPrototypeOf = Object.getPrototypeOf;
	var objectPrototype = Object.prototype;

	function hoistNonReactStatics(targetComponent, sourceComponent, blacklist) {
	    if (typeof sourceComponent !== 'string') {
	        // don't hoist over string (html) components

	        if (objectPrototype) {
	            var inheritedComponent = getPrototypeOf(sourceComponent);
	            if (inheritedComponent && inheritedComponent !== objectPrototype) {
	                hoistNonReactStatics(targetComponent, inheritedComponent, blacklist);
	            }
	        }

	        var keys = getOwnPropertyNames(sourceComponent);

	        if (getOwnPropertySymbols) {
	            keys = keys.concat(getOwnPropertySymbols(sourceComponent));
	        }

	        var targetStatics = getStatics(targetComponent);
	        var sourceStatics = getStatics(sourceComponent);

	        for (var i = 0; i < keys.length; ++i) {
	            var key = keys[i];
	            if (!KNOWN_STATICS[key] && !(blacklist && blacklist[key]) && !(sourceStatics && sourceStatics[key]) && !(targetStatics && targetStatics[key])) {
	                var descriptor = getOwnPropertyDescriptor(sourceComponent, key);
	                try {
	                    // Avoid failures from read-only properties
	                    defineProperty(targetComponent, key, descriptor);
	                } catch (e) {}
	            }
	        }

	        return targetComponent;
	    }

	    return targetComponent;
	}

	var hoistNonReactStatics_cjs = hoistNonReactStatics;

	var withCookies_1 = createCommonjsModule(function (module, exports) {

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	exports.default = withCookies;

	var React = _interopRequireWildcard(_react);



	function _interopRequireWildcard(obj) { if (obj && obj.__esModule) { return obj; } else { var newObj = {}; if (obj != null) { for (var key in obj) { if (Object.prototype.hasOwnProperty.call(obj, key)) { var desc = Object.defineProperty && Object.getOwnPropertyDescriptor ? Object.getOwnPropertyDescriptor(obj, key) : {}; if (desc.get || desc.set) { Object.defineProperty(newObj, key, desc); } else { newObj[key] = obj[key]; } } } } newObj.default = obj; return newObj; } }

	var __extends = function () {
	  var _extendStatics = function extendStatics(d, b) {
	    _extendStatics = Object.setPrototypeOf || {
	      __proto__: []
	    } instanceof Array && function (d, b) {
	      d.__proto__ = b;
	    } || function (d, b) {
	      for (var p in b) {
	        if (b.hasOwnProperty(p)) d[p] = b[p];
	      }
	    };

	    return _extendStatics(d, b);
	  };

	  return function (d, b) {
	    _extendStatics(d, b);

	    function __() {
	      this.constructor = d;
	    }

	    d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
	  };
	}();

	var __assign = function () {
	  __assign = Object.assign || function (t) {
	    for (var s, i = 1, n = arguments.length; i < n; i++) {
	      s = arguments[i];

	      for (var p in s) {
	        if (Object.prototype.hasOwnProperty.call(s, p)) t[p] = s[p];
	      }
	    }

	    return t;
	  };

	  return __assign.apply(this, arguments);
	};

	var __rest = function (s, e) {
	  var t = {};

	  for (var p in s) {
	    if (Object.prototype.hasOwnProperty.call(s, p) && e.indexOf(p) < 0) t[p] = s[p];
	  }

	  if (s != null && typeof Object.getOwnPropertySymbols === "function") for (var i = 0, p = Object.getOwnPropertySymbols(s); i < p.length; i++) {
	    if (e.indexOf(p[i]) < 0) t[p[i]] = s[p[i]];
	  }
	  return t;
	};

	// Only way to make function modules work with both TypeScript and Rollup


	function withCookies(WrapperComponent) {
	  // @ts-ignore
	  var name = WrapperComponent.displayName || WrapperComponent.name;

	  var CookieWrapper =
	  /** @class */
	  function (_super) {
	    __extends(CookieWrapper, _super);

	    function CookieWrapper() {
	      var _this = _super !== null && _super.apply(this, arguments) || this;

	      _this.onChange = function () {
	        // Make sure to update children with new values
	        _this.forceUpdate();
	      };

	      return _this;
	    }

	    CookieWrapper.prototype.listen = function () {
	      this.props.cookies.addChangeListener(this.onChange);
	    };

	    CookieWrapper.prototype.unlisten = function (cookies) {
	      (cookies || this.props.cookies).removeChangeListener(this.onChange);
	    };

	    CookieWrapper.prototype.componentDidMount = function () {
	      this.listen();
	    };

	    CookieWrapper.prototype.componentDidUpdate = function (prevProps) {
	      if (prevProps.cookies !== this.props.cookies) {
	        this.unlisten(prevProps.cookies);
	        this.listen();
	      }
	    };

	    CookieWrapper.prototype.componentWillUnmount = function () {
	      this.unlisten();
	    };

	    CookieWrapper.prototype.render = function () {
	      var _a = this.props,
	          forwardedRef = _a.forwardedRef,
	          cookies = _a.cookies,
	          restProps = __rest(_a, ["forwardedRef", "cookies"]);

	      var allCookies = cookies.getAll();
	      return React.createElement(WrapperComponent, __assign({}, restProps, {
	        ref: forwardedRef,
	        cookies: cookies,
	        allCookies: allCookies
	      }));
	    };

	    CookieWrapper.displayName = "withCookies(" + name + ")";
	    CookieWrapper.WrapperComponent = WrapperComponent;
	    return CookieWrapper;
	  }(React.Component);

	  var CookieWrapperWithRefAndCookieConsumer = React.forwardRef(function (props, ref) {
	    return React.createElement(CookiesContext_1.Consumer, null, function (cookies) {
	      return React.createElement(CookieWrapper, __assign({
	        cookies: cookies
	      }, props, {
	        forwardedRef: ref
	      }));
	    });
	  });
	  return hoistNonReactStatics_cjs(CookieWrapperWithRefAndCookieConsumer, WrapperComponent, {
	    WrappedComponent: true
	  });
	}

	module.exports = exports.default;
	});

	unwrapExports(withCookies_1);

	var useCookies_1 = createCommonjsModule(function (module, exports) {

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	exports.default = useCookies;



	var _CookiesContext = _interopRequireDefault(CookiesContext_1);

	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

	function useCookies(dependencies) {
	  var cookies = (0, _react.useContext)(_CookiesContext.default);

	  if (!cookies) {
	    throw new Error('Missing <CookiesProvider>');
	  }

	  var initialCookies = cookies.getAll();

	  var _a = (0, _react.useState)(initialCookies),
	      allCookies = _a[0],
	      setCookies = _a[1];

	  var previousCookiesRef = (0, _react.useRef)(allCookies);
	  (0, _react.useEffect)(function () {
	    function onChange() {
	      var newCookies = cookies.getAll();

	      if (shouldUpdate(dependencies || null, newCookies, previousCookiesRef.current)) {
	        setCookies(newCookies);
	      }

	      previousCookiesRef.current = newCookies;
	    }

	    cookies.addChangeListener(onChange);
	    return function () {
	      cookies.removeChangeListener(onChange);
	    };
	  }, [cookies]);
	  return [allCookies, cookies.set.bind(cookies), cookies.remove.bind(cookies)];
	}

	function shouldUpdate(dependencies, newCookies, oldCookies) {
	  if (!dependencies) {
	    return true;
	  }

	  for (var _i = 0, dependencies_1 = dependencies; _i < dependencies_1.length; _i++) {
	    var dependency = dependencies_1[_i];

	    if (newCookies[dependency] !== oldCookies[dependency]) {
	      return true;
	    }
	  }

	  return false;
	}

	module.exports = exports.default;
	});

	unwrapExports(useCookies_1);

	var cjs = createCommonjsModule(function (module, exports) {

	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	Object.defineProperty(exports, "Cookies", {
	  enumerable: true,
	  get: function get() {
	    return _Cookies.default;
	  }
	});
	Object.defineProperty(exports, "CookiesProvider", {
	  enumerable: true,
	  get: function get() {
	    return _CookiesProvider.default;
	  }
	});
	Object.defineProperty(exports, "withCookies", {
	  enumerable: true,
	  get: function get() {
	    return _withCookies.default;
	  }
	});
	Object.defineProperty(exports, "useCookies", {
	  enumerable: true,
	  get: function get() {
	    return _useCookies.default;
	  }
	});

	var _Cookies = _interopRequireDefault(Cookies);

	var _CookiesProvider = _interopRequireDefault(CookiesProvider_1);

	var _withCookies = _interopRequireDefault(withCookies_1);

	var _useCookies = _interopRequireDefault(useCookies_1);

	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }
	});

	var index = unwrapExports(cjs);

	return index;

})));
