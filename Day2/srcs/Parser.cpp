#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "../includes/Parser.hpp"

Parser::Parser(const std::string &filename) {
  std::ifstream file(filename);
  if (!file) {
	std::cerr << "Error: cannot open file" << std::endl;
	return;
  }
  _parseData(file);
}

std::vector< std::vector<int> > Parser::getData() const {
  return (_data);
}

void Parser::_parseData(std::ifstream &file) {
  std::string line;
  while (std::getline(file, line)) {
    std::vector<int> numbers;
    std::stringstream ss(line);
    int number;
    while (ss >> number)
      numbers.push_back(number);
	if (ss.fail() && !ss.eof())
	  throw std::runtime_error("Error: Failed to parse number in line: " + line);
    _data.push_back(numbers);
  }
}
