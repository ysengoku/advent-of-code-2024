/* Copyright [2024] ysengoku */

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

#include "../includes/Parser.hpp"
#include "../includes/utils.hpp"

Parser::Parser(const std::string &path1, const std::string &path2) {
  parseRules(path1);
  parseUpdates(path2);
}

const std::vector<std::pair<int, int>> Parser::getRulesData() const {
  return (_rulesData);
}

const std::vector<std::vector<int>> Parser::getUpdatesData() const {
  return (_updatesData);
}

void Parser::parseRules(const std::string &path) {
  std::ifstream file(path);
  std::string line;
  while (std::getline(file, line)) {
	size_t pos = line.find('|');
	_rulesData.push_back(std::make_pair(std::stoi(line.substr(0, pos)),
										std::stoi(line.substr(pos + 1))));
  }
  // printVectorIntPair(_rulesData);
}

void Parser::parseUpdates(const std::string &path) {
  std::ifstream file(path);
  std::string line;
  while (std::getline(file, line)) {
	std::vector<int> update;
	std::string buffer;
	std::istringstream iss(line.c_str());
	while (std::getline(iss, buffer, ',')) {
	  update.push_back(std::stoi(buffer));
	}
	_updatesData.push_back(update);
  }
  // printVectorVectorInt(_updatesData);
}
