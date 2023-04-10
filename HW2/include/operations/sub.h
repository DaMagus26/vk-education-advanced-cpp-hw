#pragma once
#include "../interface_calculatable.h"
#include <memory>

class Sub : public ICalculatable {
 public:
  Sub() = delete;
  Sub(const ICalculatable& l, const ICalculatable& r);

  Sub(const Sub&) = delete;
  Sub& operator=(const ICalculatable&) = delete;

  double calculate() const override;
  std::unique_ptr<ICalculatable> clone() const override;

  const int precedence = 6;
 private:
  std::unique_ptr<ICalculatable> left;
  std::unique_ptr<ICalculatable> right;
};