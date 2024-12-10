/* Copyright [2024] ysengoku */

#include <iostream>
#include <vector>

#include "../includes/utils.hpp"

std::ostream &operator<<(std::ostream &os, const equation &line) {
  os << line.first << ": ";
  std::vector<long>::const_iterator itEnd = line.second.end();
  for (std::vector<long>::const_iterator it = line.second.begin(); it != itEnd;
       ++it)
    os << *it << " ";
  return os;
}
