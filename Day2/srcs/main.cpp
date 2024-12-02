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
  std::vector< std::vector<int> >::iterator itEnd = data.end();
  for (std::vector< std::vector<int> >::iterator it = data.begin(); it != itEnd; ++it) {
    // printVector(*it);
    if (SafeChecker::isSafe(*it)) {
      ++count;
    }
  }
  std::cout << "Number of safe reports: " << count << std::endl;
  return (0);
}
