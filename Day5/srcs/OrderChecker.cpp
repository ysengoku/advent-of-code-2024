/* Copyright [2024] ysengoku */

#include "../includes/OrderChecker.hpp"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../includes/utils.hpp"

OrderChecker::OrderChecker(std::vector<std::pair<int, int>> const &rulesData,
                           std::vector<std::vector<int>> const &updatesData)
    : _rulesData(rulesData), _updatesData(updatesData) {
  _extractCorrectlyOrderedUpdates();
}

std::vector< std::vector<int> > OrderChecker::getCorrectlyOrderedUpdates(void) const {
  return (_correctlyOrderedUpdates);
}

void OrderChecker::_extractCorrectlyOrderedUpdates(void) {
  std::vector<std::vector<int>>::iterator itEnd = _updatesData.end();
  for (std::vector<std::vector<int>>::iterator it = _updatesData.begin();
       it != itEnd; ++it) {
    if (_isCorrectlyOrdered(*it))
      _correctlyOrderedUpdates.push_back(*it);
    else
	  _incorrectlyOrderedUpdates.push_back(*it);
  }
//   std::cout << "Correctly ordered updates: " << std::endl;
//   printVectorVectorInt(_correctlyOrderedUpdates);
  std::cout << std::endl << "Incorrectly ordered updates: " << std::endl;
  printVectorVectorInt(_incorrectlyOrderedUpdates);
}

bool OrderChecker::_isCorrectlyOrdered(std::vector<int> const &update) {
  std::vector<int>::const_iterator itEnd = update.end();
  for (std::vector<int>::const_iterator it = update.begin(); it != itEnd;
       ++it) {
    // fined pair of rules that contains the current page number
    std::vector<int> before;
    std::vector<int> after;
    std::vector<std::pair<int, int>>::iterator itRulesEnd = _rulesData.end();
    for (std::vector<std::pair<int, int>>::iterator itRules =
             _rulesData.begin();
         itRules != itRulesEnd; ++itRules) {
      if (itRules->first == *it) after.push_back(itRules->second);
      if (itRules->second == *it) before.push_back(itRules->first);
    }
    // check rule
    std::vector<int>::iterator itBeforeEnd = before.end();
    for (std::vector<int>::iterator itBefore = before.begin();
         itBefore != itBeforeEnd; ++itBefore) {
      if (std::find(it, update.end(), *itBefore) != update.end())
        return (false);
    }
    std::vector<int>::iterator itAfterEnd = after.end();
    for (std::vector<int>::iterator itAfter = after.begin();
         itAfter != itAfterEnd; ++itAfter) {
      if (std::find(update.begin(), it, *itAfter) != it) return (false);
    }
  }
  return (true);
}

void OrderChecker::printSumOfMiddlePageNumbers(void) {
  std::cout << "Result: " << calculateSumOfMiddlePageNumbers(_correctlyOrderedUpdates) << std::endl;
}
