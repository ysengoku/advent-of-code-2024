/* Copyright [2024] ysengoku */

#ifndef DAY4_INCLUDES_PARSER_HPP_
#define DAY4_INCLUDES_PARSER_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define stringVector std::vector<std::string>

class Parser {
 public:
  explicit Parser(const std::string &filename);
  std::vector<std::string> getData() const;

 private:
  void _parseData(std::ifstream &file);

  stringVector _data;
};

template <typename T>
void printVector(const std::vector<T> &vec) {
  for (const auto &elem : vec) {
    std::cout << elem << std::endl;
  }
}

#endif  // DAY4_INCLUDES_PARSER_HPP_
