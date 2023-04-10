#include "../../include/operations/sub.h"
#include <memory>

Sub::Sub(const ICalculatable &l, const ICalculatable &r) {
  left = l.clone();
  right = r.clone();
}

std::unique_ptr<ICalculatable> Sub::clone() const {
  return std::make_unique<Sub>(*left, *right);
}

double Sub::calculate() const {
  return left->calculate() - right->calculate();
}