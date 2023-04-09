#include <iostream>
#include "include/calculator.h"

int main(int argc, char** argv) {
  std::string input(argv[1]);
  Calculator calc(input);
  std::cout << calc.calculate() << std::endl;
  return 0;
}