/* Copyright [2024] ysengoku */

#ifndef DAY5_INCLUDES_UTILS_HPP_
#define DAY5_INCLUDES_UTILS_HPP_

#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
void printVector(const std::vector<T> &vector) {
  typename std::vector<T>::const_iterator itEnd = vector.end();
  for (typename std::vector<T>::const_iterator it = vector.begin(); it != itEnd; ++it) {
	std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void printVectorIntPair(const std::vector<std::pair<int, int>> &vector);
void printVectorVectorInt(const std::vector<std::vector<int>> &vector);
int calculateSumOfMiddlePageNumbers(std::vector<std::vector<int>> const &data);

#endif  // DAY5_INCLUDES_UTILS_HPP_
