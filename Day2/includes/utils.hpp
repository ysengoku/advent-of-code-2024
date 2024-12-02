#ifndef INCLUDES_UTILS_HPP_
#define INCLUDES_UTILS_HPP_

#include <iostream>
#include <vector>

template<typename T>
void printVector(const std::vector<T> &vec) {
  typename std::vector<T>::const_iterator itEnd = vec.end();
  for (typename std::vector<T>::const_iterator it = vec.begin(); it != itEnd; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

#endif // INCLUDES_UTILS_HPP_
