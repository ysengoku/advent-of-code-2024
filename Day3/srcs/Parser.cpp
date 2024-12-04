/* Copyright [2024] ysengoku */

#include "../includes/Parser.hpp"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

Parser::Parser(std::string const &filename, int partNo) : _partNo(partNo) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Error: cannot open file" << std::endl;
    return;
  }
  if (_partNo == 1)
    _parseDataPart1(file);
  else
    _parseDataPart2(file);
  file.close();
}

std::vector<std::pair<int, int> > Parser::getData() const { return (_data); }

void Parser::_parseDataPart1(std::ifstream &file) {
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

void Parser::_parseDataPart2(std::ifstream &file) {
  std::string line;
  bool enable = true;

  std::regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
  std::regex doPattern("do\\(\\)");
  std::regex dontPattern("don't\\(\\)");
  std::regex patterns[3] = {mulPattern, doPattern, dontPattern};

  while (std::getline(file, line)) {
    while (!line.empty()) {
      size_t patternIndex = 0;
      std::optional<size_t> firstMatchPosition;
      std::smatch firstMatch;
      for (size_t i = 0; i < 3; i++) {
        std::smatch match;
        if (std::regex_search(line, match, patterns[i])) {
          if (!firstMatchPosition ||
              static_cast<unsigned long>(match.position()) <
                  firstMatchPosition.value()) {
            firstMatchPosition = match.position();
            firstMatch = match;
            patternIndex = i;
          }
        }
      }
      if (!firstMatchPosition) break;
      if (patternIndex == 0) {
        if (enable) {
          try {
            int num1 = stoi(firstMatch[1]);
            int num2 = stoi(firstMatch[2]);
            _data.push_back(std::make_pair(num1, num2));
          } catch (const std::invalid_argument &e) {
          }
        }
      } else if (patternIndex == 1) {
        enable = true;
      } else if (patternIndex == 2) {
        enable = false;
      }
      line = line.substr(firstMatch.position() + firstMatch.length());
    }
  }
}
