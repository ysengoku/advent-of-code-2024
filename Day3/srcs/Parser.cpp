/* Copyright [2024] ysengoku */

#include "../includes/Parser.hpp"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

Parser::Parser(std::string const &filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Error: cannot open file" << std::endl;
    return;
  }
  _parseData(file);
  file.close();
}

std::vector<std::pair<int, int> > Parser::getData() const { return (_data); }

void Parser::_parseData(std::ifstream &file) {
  std::vector<std::pair<int, int> > data;
  std::regex pattern("mul\\(([0-9]+),([0-9]+)\\)");
  std::string line;

  while (std::getline(file, line)) {
    std::smatch matches;
    while (regex_search(line, matches, pattern)) {
      try {
        int num1 = stoi(matches[1]);
        int num2 = stoi(matches[2]);
        _data.push_back(std::make_pair(num1, num2));
      } catch (const std::invalid_argument &e) {
      }
      line = matches.suffix().str();
    }
  }
}
