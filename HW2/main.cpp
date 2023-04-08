#include <iostream>
//#include "include/tokenizer.h"
//#include "include/calculator.h"
#include "include/interface_calculatable.h"
#include "include/operations.h"

int main(int argc, char** argv) {
  Number n1{10.2};
  Number n2{22.0};
  Number n3{9.2};
  Number n4{4};
  Add add_node{n1, n2};
  Sqrt sqrt_node{n4};
  Mul mul_node{n3, sqrt_node};
  Ceil ceil_node{mul_node};
  Sub sub_node{add_node, ceil_node};

  std::cout << sub_node.calculate() << std::endl;

  std::cout << "Worked fine" << std::endl;
  return 0;
}