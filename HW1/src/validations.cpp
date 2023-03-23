#include "validations.h"
#include <boost/program_options.hpp>
#include <iostream>

bool ValidateAndStore(const po::variables_map& vm, const std::string& field, std::string& storage) {
  if (vm.count(field)) {
    storage = vm[field].as<std::string>();
    return true;
  } else {
    std::cout << field << " is not provided" << std::endl;
    return false;
  }
}
