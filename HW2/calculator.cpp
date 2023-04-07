#include <iostream>
#include "include/tokenizer.h"

int main() {
  auto tokens = tokenizeString("10 + 12.0 / (0.0-1) * sqrt(10) - ceil(15 + 2) * carl 10");
  for (const auto& token: tokens) {
    std::cout << token << " ";
  }
  std::cout << std::endl;
  return 0;
}