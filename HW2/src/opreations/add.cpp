#include "../../include/operations/add.h"
#include <memory>

Add::Add(const ICalculatable &l, const ICalculatable &r) {
  left = l.clone();
  right = r.clone();
}

std::unique_ptr<ICalculatable> Add::clone() const {
  return std::make_unique<Add>(*left, *right);
}

double Add::calculate() const {
  return left->calculate() + right->calculate();
}