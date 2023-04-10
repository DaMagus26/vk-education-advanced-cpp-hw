#pragma once
#include "interface_calculatable.h"
#include "../include/factory_functions.h"
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <stack>

class Calculator {
 public:
  Calculator() : root(nullptr) {}
  Calculator(const Calculator&) = delete;
  Calculator& operator=(const Calculator&) = delete;
  explicit Calculator(const std::string&);

  [[nodiscard]] double calculate() const;
 private:
  static bool isSpace(char);
  static bool isDotNum(char);
  static bool isTextOperator(const std::string&);
  static bool isOperator(char);
  static bool isValidDouble(const std::string&);
  static std::vector<std::string> tokenizeExpression(const std::string&);
  [[nodiscard]] std::vector<std::string> postfixNotation(const std::vector<std::string>&) const;
  std::unique_ptr<ICalculatable> buildTree(const std::vector<std::string>&) const;

  struct OperationMetaData {
    int precedence;
    bool binary;

  };

  const std::map<std::string, int> precedence{
      {"(", 0},
      {")", 0},
      {"+", 1},
      {"-", 1},
      {"*", 2},
      {"sqrt", 3},
      {"ceil", 3}
  };

  const std::map<std::string, factoryFunction> factory{
      {"+", createAdd},
      {"-", createSub},
      {"*", createMul},
      {"sqrt", createSqrt},
      {"ceil", createCeil}
  };


  std::unique_ptr<ICalculatable> root;
};