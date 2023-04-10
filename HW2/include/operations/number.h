#pragma once
#include "../interface_calculatable.h"
#include <memory>

class Number final : public ICalculatable {
 public:
  Number() = delete;
  explicit Number(double);

  double calculate() const override;
  std::unique_ptr<ICalculatable> clone() const override;
 private:
  double value;
};