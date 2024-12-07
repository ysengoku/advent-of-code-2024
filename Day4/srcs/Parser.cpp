/* Copyright [2024] ysengoku */

#include "../includes/Parser.hpp"

#include <fstream>
#include <iostream>
#include <string>
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

std::vector<std::string> Parser::getData() const { return (_data); }

void Parser::_parseData(std::ifstream &file) {
  std::string line;
  while (std::getline(file, line)) {
    _data.push_back(line);
  }
  // printVector(_data);
}
