var CludoSearch;
(function () {
  var cludoSettings = {
    customerId: 2719,
    engineId: 12014,
    searchUrl: '',
    language: 'en',
    searchInputs: ['cludo-search-form-english'],
    template: 'InlineBasic',
    focusOnResultsAfterSearch: true
  };
  CludoSearch = new Cludo(cludoSettings);
  CludoSearch.init();
})();
