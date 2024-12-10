/* Copyright [2024] ysengoku */

#ifndef DAY7_INCLUDES_CALCULATOR_HPP_
#define DAY7_INCLUDES_CALCULATOR_HPP_
#include <string>
#include <utility>
#include <vector>

typedef std::pair<long, std::vector<long> > equation;

class Calculator {
 public:
  Calculator(const std::vector<equation> &data);

  void calculate(void);

 private:
  const std::vector<equation> &_data;
  std::vector<long> _validNumbers;
  bool _checkEquation(long left, const std::vector<long> &right, size_t index, long sum);
};

#endif // DAY7_INCLUDES_CALCULATOR_HPP_
