#include "validations.h"
#include <map>
#include <iostream>

bool ValidateAndStore(std::map<std::string, std::string>& vm, const std::string& field, std::string& storage) {
  if (vm.find(field) != vm.end()) {
    storage = vm[field];
    return true;
  } else {
    std::cout << field << " is not provided" << std::endl;
    return false;
  }
}
