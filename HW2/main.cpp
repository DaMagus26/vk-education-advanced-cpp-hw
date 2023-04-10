#include <iostream>
#include "include/calculator.h"
#include "include/printer.h"

int main(int argc, char** argv) {
  std::string input(argv[1]);
  Calculator calc(input);
  printer(std::cout, calc.calculate());
  return 0;
}