#include <iostream>
//#include "include/tokenizer.h"
//#include "include/calculator.h"
#include "include/interface_calculatable.h"


class Calc : public ICalculatable {
  double calculate() const override { return 0; }
};

void some_func(ICalculatable& c) {
}

int main(int argc, char** argv) {
  std::string input = "";

  std::cout << "Worked fine" << std::endl;
  return 0;
}