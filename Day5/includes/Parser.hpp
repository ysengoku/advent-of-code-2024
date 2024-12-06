/* Copyright [2024] ysengoku */

#ifndef DAY5_INCLUDES_PARSER_HPP_
#define DAY5_INCLUDES_PARSER_HPP_

#include <string>
#include <utility>
#include <vector>

class Parser {
 public:
  explicit Parser(std::string const &path1, std::string const &path2);
  const std::vector<std::pair<int, int>> getRulesData() const;
  const std::vector<std::vector<int>> getUpdatesData() const;

 private:
  std::vector<std::pair<int, int>> _rulesData;
  std::vector<std::vector<int>> _updatesData;

  void parseRules(std::string const &path);
  void parseUpdates(std::string const &path);
};

#endif  // DAY5_INCLUDES_PARSER_HPP_