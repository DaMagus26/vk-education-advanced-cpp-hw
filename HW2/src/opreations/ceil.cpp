#include "../../include/operations/ceil.h"
#include <memory>
#include <cmath>

Ceil::Ceil(const ICalculatable &l) {
  child = l.clone();
}

std::unique_ptr<ICalculatable> Ceil::clone() const {
  return std::make_unique<Ceil>(*child);
}

double Ceil::calculate() const {
  return std::ceil(child->calculate());
}