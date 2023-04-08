#include "../include/operations.h"
#include <memory>
#include <cmath>

Number::Number(double d) {
  value = d;
}

std::unique_ptr<ICalculatable> Number::clone() const {
  return std::make_unique<Number>(this->value);
}

double Number::calculate() const {
  return value;
}

Add::Add(const ICalculatable &l, const ICalculatable &r) {
  left = l.clone();
  right = r.clone();
}

std::unique_ptr<ICalculatable> Add::clone() const {
  return std::make_unique<Add>(*left, *right);
}

double Add::calculate() const {
  return left->calculate() + right->calculate();
}

Sub::Sub(const ICalculatable &l, const ICalculatable &r) {
  left = l.clone();
  right = r.clone();
}

std::unique_ptr<ICalculatable> Sub::clone() const {
  return std::make_unique<Sub>(*left, *right);
}

double Sub::calculate() const {
  return left->calculate() - right->calculate();
}

Mul::Mul(const ICalculatable &l, const ICalculatable &r) {
  left = l.clone();
  right = r.clone();
}

std::unique_ptr<ICalculatable> Mul::clone() const {
  return std::make_unique<Mul>(*left, *right);
}

double Mul::calculate() const {
  return left->calculate() * right->calculate();
}

Sqrt::Sqrt(const ICalculatable &l) {
  child = l.clone();
}

std::unique_ptr<ICalculatable> Sqrt::clone() const {
  return std::make_unique<Sqrt>(*child);
}

double Sqrt::calculate() const {
  return std::sqrt(child->calculate());
}

Ceil::Ceil(const ICalculatable &l) {
  child = l.clone();
}

std::unique_ptr<ICalculatable> Ceil::clone() const {
  return std::make_unique<Ceil>(*child);
}

double Ceil::calculate() const {
  return std::ceil(child->calculate());
}

