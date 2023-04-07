#pragma once
#include "interface_calculatable.h"
#include <string>
#include <vector>

class Calculatable : ICalculatable {
 public:
  Calculatable() = default;;
  Calculatable(const std::string&);
//  Calculatable(const Calculatable&);
//  Calculatable(Calculatable&&);
//  ~Calculatable();

//  Calculatable& operator=(const Calculatable&);
//  Calculatable& operator=(Calculatable&&);

//  virtual double Calculate() override;
 private:
};

