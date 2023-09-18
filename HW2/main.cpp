#include <iostream>
#include "include/calculator.h"
#include "include/printer.h"

int main(int argc, char** argv) {

  if (argc < 1) {
    std::cerr << "Not enough arguments" << std::endl;
    return 1;
  }

  std::string input(argv[1]);
  Calculator calc(input);
  printer(std::cout, calc.calculate());
  return 0;
}