/* Copyright [2024] ysengoku */

#ifndef DAY5_INCLUDES_ORDERSETTER_HPP_
#define DAY5_INCLUDES_ORDERSETTER_HPP_

#include <utility>
#include <vector>

class OrderCorrector {
 public:
  OrderCorrector(std::vector<std::pair<int, int>> const &rulesData,
			  std::vector<std::vector<int>> const &incorrectlyOrderedUpdates);
  
  void printSumOfMiddlePageNumbers(void);

 private:
  std::vector< std::pair<int, int> > _rulesData;
  std::vector< std::vector<int> > _incorrectlyOrderedUpdates;
  std::vector< std::vector<int> > _correctedUpdates;

  void _correctOrder(void);
  std::vector<int> _putUpdateInOrder(const std::vector<int> &update);
};

#endif // DAY5_INCLUDES_ORDERSETTER_HPP_