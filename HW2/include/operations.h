#pragma once
#include "interface_calculatable.h"
#include <memory>

class Number : public ICalculatable {
 public:
  Number() = delete;
  explicit Number(double);

  double calculate() const override;
  std::unique_ptr<ICalculatable> clone() const override;
 private:
  double value;
};

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

class Mul : public ICalculatable {
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

class Sqrt : public ICalculatable {
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

class Ceil : public ICalculatable {
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