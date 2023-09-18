#pragma once
#include "../interface_calculatable.h"
#include <memory>

class Ceil final : public ICalculatable {
 public:
  Ceil() = delete;
  explicit Ceil(const ICalculatable& l);

  Ceil(const Ceil&) = delete;
  Ceil& operator=(const ICalculatable&) = delete;

  double calculate() const override;
  std::unique_ptr<ICalculatable> clone() const override;

  const int precedence = 2;
 private:
  std::unique_ptr<ICalculatable> child;
};