/* Copyright [2024] ysengoku */

#ifndef DAY4_INCLUDES_XMASCOUNTER_HPP_
#define DAY4_INCLUDES_XMASCOUNTER_HPP_

#define CYAN "\033[36m"
#define RESET "\033[0m"

#include <string>
#include <vector>

class XmasCounter {
 public:
  explicit XmasCounter(const std::vector<std::string> &data);
  int getCount(void) const;

 private:
  const std::vector<std::string> *_data;
  int _count;

  void _countXmas(void);
  bool _checkDiagonalLeftToRight(size_t indexColumn, size_t indexRow);
  bool _checkDiagonalRightToLeft(size_t indexColumn, size_t indexRow);
};

#endif  // DAY4_INCLUDES_XMASCOUNTER_HPP_
