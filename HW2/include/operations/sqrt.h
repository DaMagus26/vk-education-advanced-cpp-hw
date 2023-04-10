#pragma once
#include "../interface_calculatable.h"
#include <memory>

class Sqrt final : public ICalculatable {
 public:
  Sqrt() = delete;

  explicit Sqrt(const ICalculatable& l);

  Sqrt(const Sqrt&) = delete;
  Sqrt& operator=(const ICalculatable&) = delete;

  double calculate() const override;
  std::unique_ptr<ICalculatable> clone() const override;

  const int precedence = 2;
 private:
  std::unique_ptr<ICalculatable> child;
};