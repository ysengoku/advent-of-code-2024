/* Copyright [2024] ysengoku */

#ifndef DAY5_INCLUDES_ORDERCHECKER_HPP_
#define DAY5_INCLUDES_ORDERCHECKER_HPP_

#include <string>
#include <utility>
#include <vector>

class OrderChecker {
 public:
  OrderChecker(std::vector<std::pair<int, int> > const &rulesData,
              std::vector<std::vector<int> > const &updatesData);

  void printSumOfMiddlePageNumbers(void);
  std::vector< std::vector<int> > getCorrectlyOrderedUpdates(void) const;

 private:
  std::vector<std::pair<int, int> > _rulesData;
  std::vector<std::vector<int> > _updatesData;
  std::vector<std::vector<int> > _correctlyOrderedUpdates;
  std::vector< std::vector<int> > _incorrectlyOrderedUpdates;
  std::vector<int> _middlePageNumbers;

  void _extractCorrectlyOrderedUpdates(void);
  bool _isCorrectlyOrdered(std::vector<int> const &update);
  int _calculateSumOfMiddlePageNumbers(void);
};

#endif  // DAY5_INCLUDES_ORDERCHECKER_HPP_
