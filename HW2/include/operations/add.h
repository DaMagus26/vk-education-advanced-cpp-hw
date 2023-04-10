#pragma once
#include "../interface_calculatable.h"
#include <memory>

class Add : public ICalculatable {
 public:
  Add() = delete;
  Add(const ICalculatable& l, const ICalculatable& r);

  Add(const Add&) = delete;
  Add& operator=(const ICalculatable&) = delete;

  double calculate() const override;
  std::unique_ptr<ICalculatable> clone() const override;

  const int precedence = 6;
 private:
  std::unique_ptr<ICalculatable> left;
  std::unique_ptr<ICalculatable> right;
};