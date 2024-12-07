/* Copyright [2024] ysengoku */

#ifndef DAY6_INCLUDES_PARSER_HPP_
#define DAY6_INCLUDES_PARSER_HPP_

#include <string>
#include <vector>

class Parser {
 public:
  Parser(const std::string &filename);

  const std::vector<std::string> &getMap(void) const;

 private:
  std::vector<std::string> _map;

  void _parseFile(const std::string &filename);
};

#endif  // DAY6_INCLUDES_PARSER_HPP_