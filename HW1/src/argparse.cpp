#include <map>
#include <vector>
#include <iostream>
#include <utility>
#include "string_actions.h"
#include "argparse.h"

std::map<std::string, std::string> ParseCmdLineOptions(int argc, const char** argv) {
  std::map<std::string, std::string> params;

  for (int i = 1; i < argc; ++i) {
    const std::string par(argv[i]);
    if (par.rfind("--", 0) == 0) {
       std::vector<std::string> par_key_value;
       SplitString(par, std::back_inserter(par_key_value), '=');
       std::string par_key = std::string(par_key_value[0].begin() + 2, par_key_value[0].end());
       std::string par_value = par_key_value[1];
       params.insert({par_key, par_value});
    } else {
      std::cerr << "Invalid argument: " << par << std::endl;
      return {};
    }
  }

  return params;
}
