/* Copyright [2024] ysengoku */

#ifndef DAY7_INCLUDES_PARSER_HPP_
#define DAY7_INCLUDES_PARSER_HPP_

#include <string>
#include <utility>
#include <vector>

typedef std::pair<long, std::vector<long> > equation;

class Parser {
 public:
  Parser(const std::string &filename);

  const std::vector<equation> &getData(void) const;

 private:
  std::vector<equation> _data;

  void _parseFile(const std::string &filename);
};

#endif  // DAY7_INCLUDES_PARSER_HPP_