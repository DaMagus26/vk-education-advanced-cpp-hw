#pragma once
#include "../interface_calculatable.h"
#include <memory>

class Mul final : public ICalculatable {
 public:
  Mul() = delete;
  Mul(const ICalculatable& l, const ICalculatable& r);

  Mul(const Mul&) = delete;
  Mul& operator=(const ICalculatable&) = delete;

  double calculate() const override;
  std::unique_ptr<ICalculatable> clone() const override;

  const int precedence = 5;
 private:
  std::unique_ptr<ICalculatable> left;
  std::unique_ptr<ICalculatable> right;
};