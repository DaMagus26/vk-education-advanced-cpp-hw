#pragma once
#include "operations.h"
#include <memory>
#include <string>
#include <vector>

class Calculator {
 public:
  Calculator() : root(nullptr) {}
  Calculator(const Calculator&) = delete;
  Calculator& operator=(const Calculator&) = delete;
  Calculator(const std::string&);

  double calculate() const;
 private:
  static bool isSpace(const char);
  static bool isDotNum(const char);
  static bool isTextOperator(const std::string&);
  static bool isOperator(const char);
  static std::vector<std::string> tokenizeExpression(const std::string&) ;
  static std::unique_ptr<ICalculatable> buildTree(const std::vector<std::string>&) ;
  std::unique_ptr<ICalculatable> root;
};