#pragma once
#include "operations.h"
#include <memory>
#include <string>
#include <vector>
#include <map>

class Calculator {
 public:
  Calculator() : root(nullptr) {}
  Calculator(const Calculator&) = delete;
  Calculator& operator=(const Calculator&) = delete;
  explicit Calculator(const std::string&);

  double calculate() const;
 private:
  static bool isSpace(char);
  static bool isDotNum(char);
  static bool isTextOperator(const std::string&);
  static bool isOperator(char);
  static bool isValidDouble(const std::string&);
  static std::vector<std::string> tokenizeExpression(const std::string&);
  std::vector<std::string> postfixNotation(const std::vector<std::string>&);
  static std::unique_ptr<ICalculatable> buildTree(const std::vector<std::string>&) ;
  std::unique_ptr<ICalculatable> root;
};