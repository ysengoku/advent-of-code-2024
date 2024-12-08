/* Copyright [2024] ysengoku */

#ifndef DAY6_INCLUDES_UTILS_HPP_
#define DAY6_INCLUDES_UTILS_HPP_

#include <iostream>
#include <vector>

#include "../includes/ObstructionSimulator.hpp"

template <typename T>
void printVector(const std::vector<T> &vec) {
  for (const auto &elem : vec) {
	std::cout << elem << std::endl;
  }
}

struct Vector2D;
std::ostream &operator<<(std::ostream &os, const Vector2D &vec2d);

template void printVector<Vector2D>(const std::vector<Vector2D> &vector);

#endif  // DAY6_INCLUDES_UTILS_HPP_
