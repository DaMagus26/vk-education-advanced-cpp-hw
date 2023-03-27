#include "output.h"
#include <iostream>
#include <map>

void PrintResult(const std::map<std::string, std::string>& titles, const std::string& name) {
  if (titles.empty()) {
    std::cout << "There are no relevant movies, which starred " << name << std::endl;
  } else {
    for (const auto& x: titles) {
      std::cout << x.second << std::endl;
    }
  }
}