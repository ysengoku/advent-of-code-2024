/* Copyright [2024] ysengoku */

#ifndef DAY3_INCLUDES_PARSER_HPP_
#define DAY3_INCLUDES_PARSER_HPP_

#include <string>
#include <utility>
#include <vector>

class Parser {
 public:
  explicit Parser(std::string const &filename, int partNo);
  std::vector<std::pair<int, int> > getData() const;

 private:
  std::vector<std::pair<int, int> > _data;
  int _partNo;
  // bool _do;

  void _parseDataPart1(std::ifstream &file);
  void _parseDataPart2(std::ifstream &file);
};

#endif  // DAY3_INCLUDES_PARSER_HPP_
