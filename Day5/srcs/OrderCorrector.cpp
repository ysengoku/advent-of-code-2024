/* Copyright [2024] ysengoku */

#include <iostream>
#include <string>
#include <vector>

#include "../includes/OrderCorrector.hpp"
#include "../includes/utils.hpp"

OrderCorrector::OrderCorrector(
    std::vector<std::pair<int, int>> const &rulesData,
    std::vector<std::vector<int>> const &incorrectlyOrderedUpdates)
    : _rulesData(rulesData),
      _incorrectlyOrderedUpdates(incorrectlyOrderedUpdates) {
  _correctOrder();
}

void OrderCorrector::_correctOrder(void) {
  // std::cout << "===== Incorrectly ordered updates =====" << std::endl;
  // printVectorVectorInt(_incorrectlyOrderedUpdates);
  std::vector<std::vector<int>>::iterator itEnd =
      _incorrectlyOrderedUpdates.end();
  for (std::vector<std::vector<int>>::iterator it =
           _incorrectlyOrderedUpdates.begin();
       it != itEnd; ++it) {
    // printVector(*it);
    std::vector<int> correctedUpdate = _putInCorrectOrder(*it);
    _correctedUpdates.push_back(correctedUpdate);
  }
  // std::cout << std::endl << "===== Corrected updates =====" << std::endl;
  // printVectorVectorInt(_correctedUpdates);
}

std::vector<int> OrderCorrector::_putInCorrectOrder(const std::vector<int> &update) {
  std::vector<int> correctedUpdate;
  correctedUpdate.push_back(update[0]);
  std::vector<int>::const_iterator itEnd = update.end();
  for (std::vector<int>::const_iterator it = update.begin() + 1; it != itEnd;
	   ++it) {
	  std::vector<int> before;
	  std::vector<int> after;
	  std::vector<std::pair<int, int>>::iterator itRulesEnd = _rulesData.end();
	  for (std::vector<std::pair<int, int>>::iterator itRules = _rulesData.begin();
		  itRules != itRulesEnd; ++itRules) {
	    if (itRules->first == *it) after.push_back(itRules->second);
	    if (itRules->second == *it) before.push_back(itRules->first);
	  }
    size_t len = correctedUpdate.size();
    bool inserted = false;
    for (size_t i = 0; i < len; ++i) {
      if (std::find(after.begin(), after.end(), correctedUpdate[i]) != after.end()) {
        correctedUpdate.insert(correctedUpdate.begin() + i, *it);
        inserted = true;
        break;
      }
    }
    if (!inserted)
      correctedUpdate.push_back(*it);
  }
  return (correctedUpdate);
}

void OrderCorrector::printSumOfMiddlePageNumbers(void) {
  std::cout << "Result: " << calculateSumOfMiddlePageNumbers(_correctedUpdates) << std::endl;
}
