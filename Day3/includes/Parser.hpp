/* Copyright [2024] ysengoku */

#ifndef DAY3_INCLUDES_PARSER_HPP_
#define DAY3_INCLUDES_PARSER_HPP_

#include <string>
#include <utility>
#include <vector>

class Parser {
 public:
  explicit Parser(std::string const &filename);
  std::vector<std::pair<int, int> > getData() const;

 private:
  std::vector<std::pair<int, int> > _data;

  void _parseData(std::ifstream &file);
};

#endif  // DAY3_INCLUDES_PARSER_HPP_
