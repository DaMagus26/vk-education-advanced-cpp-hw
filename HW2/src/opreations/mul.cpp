#include "../../include/operations/mul.h"
#include <memory>

Mul::Mul(const ICalculatable &l, const ICalculatable &r) {
  left = l.clone();
  right = r.clone();
}

std::unique_ptr<ICalculatable> Mul::clone() const {
  return std::make_unique<Mul>(*left, *right);
}

double Mul::calculate() const {
  return left->calculate() * right->calculate();
}