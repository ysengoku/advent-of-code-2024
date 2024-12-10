/* Copyright [2024] ysengoku */

#include <iostream>
#include <string>
#include <vector>

#include "../includes/Calculator.hpp"
#include "../includes/Parser.hpp"
// #include "../includes/utils.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Usage: " << av[0] << " <filename>" << std::endl;
    return (1);
  }
  std::vector<equation> data = Parser(av[1]).getData();
  Calculator(data).calculate();
  return (0);
}
