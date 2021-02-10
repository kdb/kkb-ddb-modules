var CludoSearch;
(function () {
  var path = window.location.pathname.split('/');
  path = path[path.length - 1];
  var cludoSettings = {
    customerId: 2719,
    engineId: 12014,
    searchUrl: '/searchresult/' + path,
    language: 'en',
    searchInputs: ['cludo-search-form-english'],
    focusOnResultsAfterSearch: true
  };
  CludoSearch = new Cludo(cludoSettings);
  CludoSearch.init();
})();
