#include "../../include/operations/number.h"
#include <memory>

Number::Number(double d) {
  value = d;
}

std::unique_ptr<ICalculatable> Number::clone() const {
  return std::make_unique<Number>(this->value);
}

double Number::calculate() const {
  return value;
}