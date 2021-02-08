var CludoSearch;
(function () {
  var cludoSettings = {
    customerId: 2719,
    engineId: 11866,
    searchUrl: '',
    language: 'da',
    searchInputs: ['cludo-search-form', 'cludo-search-kontakt-form'],
    template: 'InlineBasic',
    focusOnResultsAfterSearch: true
  };
  CludoSearch = new Cludo(cludoSettings);
  CludoSearch.init();
})();
