#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "../includes/Parser.hpp"
#include "../includes/SafeChecker.hpp"
#include "../includes/utils.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "usage: " << av[0] << " file" << std::endl;
    return (1);
  }
  std::vector< std::vector<int> > data = Parser(av[1]).getData();
  
  int count = 0;
  for (size_t i = 0; i < data.size(); ) {
    // printVector(data[i]);
    if (SafeChecker::isSafe(data[i])) {
      // std::cout << i << ": Safe" << std::endl;
      data.erase(data.begin() + i);
      ++count;
    } else {
      ++i;
    }
  }
  std::cout << "Number of safe reports: " << count << std::endl;
  std::cout << "Checking remaining " << data.size() << " reports..." << std::endl;
  return (0);
}
