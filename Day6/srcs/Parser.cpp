/* Copyright [2024] ysengoku */

#include <fstream>
#include <string>

#include "../includes/Parser.hpp"
#include "../includes/utils.hpp"

Parser::Parser(const std::string &filename) {
  _parseFile(filename);
}

const std::vector<std::string> &Parser::getMap(void) const {
  return (_map);
}

void Parser::_parseFile(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
	_map.push_back(line);
  }
//   printVector(_map);
}
