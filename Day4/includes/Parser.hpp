/* Copyright [2024] ysengoku */

#ifndef DAY4_INCLUDES_PARSER_HPP_
#define DAY4_INCLUDES_PARSER_HPP_

#include <fstream>
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

#endif  // DAY4_INCLUDES_PARSER_HPP_
