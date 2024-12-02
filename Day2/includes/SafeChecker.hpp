#ifndef INCLUDES_SAFE_CHECKER_HPP_
#define INCLUDES_SAFE_CHECKER_HPP_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

class SafeChecker {
 public:
  static bool isSafe(const std::vector<int> &numbers);

 private:
  static bool _isAscending;

  static bool isSorted(const std::vector<int> &numbers);
  static bool hasNoDuplicate(const std::vector<int> &numbers);
  static bool differByLessThan4(const std::vector<int> &numbers);
};

#endif // INCLUDES_SAFE_CHECKER_HPP_
