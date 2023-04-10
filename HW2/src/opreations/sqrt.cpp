#include "../../include/operations/sqrt.h"
#include <memory>
#include <cmath>

Sqrt::Sqrt(const ICalculatable &l) {
  child = l.clone();
}

std::unique_ptr<ICalculatable> Sqrt::clone() const {
  return std::make_unique<Sqrt>(*child);
}

double Sqrt::calculate() const {
  return std::sqrt(child->calculate());
}