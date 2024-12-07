/* Copyright [2024] ysengoku */

#ifndef DAY6_INCLUDES_UTILS_HPP_
#define DAY6_INCLUDES_UTILS_HPP_

#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T> &vec) {
  for (const auto &elem : vec) {
	std::cout << elem << std::endl;
  }
}

#endif  // DAY6_INCLUDES_UTILS_HPP_