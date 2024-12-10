/* Copyright [2024] ysengoku */

#ifndef DAY7_INCLUDES_UTILS_HPP_
#define DAY7_INCLUDES_UTILS_HPP_

#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<long, std::vector<long> > equation;

std::ostream &operator<<(std::ostream &os, const equation &line);

template <typename T>
void printVector(const std::vector<T> &vec) {
  for (const auto &elem : vec) {
    std::cout << elem << std::endl;
  }
}

#endif  // DAY7_INCLUDES_UTILS_HPP_
