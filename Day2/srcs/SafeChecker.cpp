#include "../includes/SafeChecker.hpp"

bool SafeChecker::_isAscending = true;

bool SafeChecker::isSafe(const std::vector<int> &numbers) {
  if (!hasNoDuplicate(numbers) || !isSorted(numbers) || !differByLessThan4(numbers))
    return (false);
  return (true);
}

bool SafeChecker::isSorted(const std::vector<int> &numbers) {
  if (std::is_sorted(numbers.begin(), numbers.end())) {
	_isAscending = true;
	return (true);
  }
  if (std::is_sorted(numbers.rbegin(), numbers.rend())) {
	_isAscending = false;
	return (true);
  }
  return (false);
}

bool SafeChecker::hasNoDuplicate(const std::vector<int> &numbers) {
  std::vector<int> copy(numbers);
  std::sort(copy.begin(), copy.end());
  std::vector<int>::iterator itEnd = copy.end();
  for (std::vector<int>::iterator it = copy.begin(); it != itEnd; ++it) {
	if (it + 1 != itEnd && *it == *(it + 1))
	  return (false);
  }
  return (true);
}

bool SafeChecker::differByLessThan4(const std::vector<int> &numbers) {
  if (_isAscending) {
    std::vector<int>::const_iterator itEnd = numbers.end();
	for (std::vector<int>::const_iterator it = numbers.begin(); it != itEnd; ++it) {
	  if (it + 1 != itEnd && (*(it + 1) - *it) > 3)
	    return (false);
	}
	return (true);
  }
  std::vector<int>::const_reverse_iterator itRend = numbers.rend();
  for (std::vector<int>::const_reverse_iterator it = numbers.rbegin(); it != itRend; ++it) {
	if (it + 1 != itRend && abs(*it - *(it + 1)) > 3) {
	  return (false);
	}
  }
  return (true);
}
