#pragma once
#include <memory>

class ICalculatable {
 public:
  virtual double calculate() const = 0;
  virtual std::unique_ptr<ICalculatable> clone() const = 0;
  virtual ~ICalculatable() = default;
};