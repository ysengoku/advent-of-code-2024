/* Copyright [2024] ysengoku */

#include "../includes/OrderCorrector.hpp"

OrderCorrector::OrderCorrector(
    std::vector<std::pair<int, int>> const &rulesData,
    std::vector<std::vector<int>> const &incorrectlyOrderedUpdates)
    : _rulesData(rulesData),
      _incorrectlyOrderedUpdates(incorrectlyOrderedUpdates) {
  _correctOrder();
}

void OrderCorrector::_correctOrder(void) {
  std::vector<std::vector<int>>::iterator itEnd =
      _incorrectlyOrderedUpdates.end();
  for (std::vector<std::vector<int>>::iterator it =
           _incorrectlyOrderedUpdates.begin();
       it != itEnd; ++it) {
    std::vector<int> correctedUpdate = _putUpdateInOrder(*it);
    _correctedUpdates.push_back(correctedUpdate);
  }
}

std::vector<int> OrderCorrector::_putUpdateInOrder(const std::vector<int> &update) {
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
    // Find the correct position for the current page and insert threre
  }
  return (correctedUpdate);
}