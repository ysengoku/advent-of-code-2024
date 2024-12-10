/* Copyright [2024] ysengoku */

#include <string>
#include <utility>
#include <vector>

#include "../includes/Calculator.hpp"
#include "../includes/utils.hpp"

Calculator::Calculator(const std::vector<equation> &data) : _data(data) {}

void Calculator::calculate(void) {
  std::vector<equation>::const_iterator itEnd = _data.end();
  for (std::vector<equation>::const_iterator it = _data.begin(); it != itEnd;
	   ++it) {
	if (_checkEquation(it->first, it->second, 1, it->second[0])) {
	  _validNumbers.push_back(it->first);
	}
  }
//   printVector(_validNumbers);
  long res = 0;
  std::vector<long>::iterator itEndValidNumbers = _validNumbers.end();
  for (std::vector<long>::iterator itValidNumbers = _validNumbers.begin(); itValidNumbers != itEndValidNumbers;
	   ++itValidNumbers) {
	res += *itValidNumbers;
  }
  std::cout << "Part 1: " << res << std::endl;
}

bool Calculator::_checkEquation(long left, const std::vector<long> &right, size_t index, long sum) {
  if (index == right.size()) {
	return (left == sum);
  }
  if (_checkEquation(left, right, index + 1, sum + right[index]))
	return (true);
  if (_checkEquation(left, right, index + 1, sum * right[index]))
	return (true);
  return (false);
}
