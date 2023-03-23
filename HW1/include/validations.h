#pragma once

#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

bool ValidateAndStore(const po::variables_map& vm, const std::string& field, std::string& storage);