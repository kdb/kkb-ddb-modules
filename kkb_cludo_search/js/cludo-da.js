var CludoSearch;
(function () {
  var path = window.location.pathname.split('/');
  path = path[path.length - 1];
  var cludoSettings = {
    customerId: 2719,
    engineId: 11866,
    searchUrl: '/soegeresultat/' + path,
    language: 'da',
    searchInputs: ['cludo-search-form', 'cludo-search-kontakt-form'],
    focusOnResultsAfterSearch: true
  };
  CludoSearch = new Cludo(cludoSettings);
  CludoSearch.init();
})();
