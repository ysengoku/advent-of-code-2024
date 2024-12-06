/* Copyright [2024] ysengoku */

#include "../includes/utils.hpp"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

void printVectorIntPair(const std::vector<std::pair<int, int>> &vector) {
  std::vector<std::pair<int, int>>::const_iterator itEnd = vector.end();
  for (std::vector<std::pair<int, int>>::const_iterator it = vector.begin();
       it != itEnd; ++it) {
    std::cout << it->first << "|" << it->second << std::endl;
  }
}

void printVectorVectorInt(const std::vector<std::vector<int>> &vector) {
  std::vector<std::vector<int>>::const_iterator itEnd = vector.end();
  for (std::vector<std::vector<int>>::const_iterator it = vector.begin();
       it != itEnd; ++it) {
    std::vector<int>::const_iterator itEnd2 = it->end();
    for (std::vector<int>::const_iterator it2 = it->begin(); it2 != itEnd2;
         ++it2) {
      std::cout << *it2 << " ";
    }
    std::cout << std::endl;
  }
}

int calculateSumOfMiddlePageNumbers(const std::vector<std::vector<int>> &data) {
  int sum = 0;
  std::vector<std::vector<int>>::const_iterator itEnd =
      data.end();
  for (std::vector<std::vector<int>>::const_iterator it =
           data.begin();
       it != itEnd; ++it) {
    size_t middlePos = it->size() / 2;
    sum += (*it)[middlePos];
  }
  return (sum);
}
