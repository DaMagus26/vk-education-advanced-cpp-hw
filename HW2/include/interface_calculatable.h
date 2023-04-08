#pragma once

class ICalculatable {
 public:
  virtual double calculate() const = 0;
  ~ICalculatable() = default;;
};