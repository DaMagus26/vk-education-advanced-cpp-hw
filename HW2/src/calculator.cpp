#include "../include/calculator.h"
#include "../include/operations.h"
#include <string>
#include <memory>
#include <vector>

Calculator::Calculator(const std::string &str) {
  if (str.empty()) {
    root = nullptr;
    return;
  }

  std::vector<std::string> tokens = tokenizeExpression(str);
  root = buildTree(tokens);
}

double Calculator::calculate() const {
  return root->calculate();
}

bool Calculator::isSpace(const char c) {
  return c == ' ';
}

// Checks is given character is a digit or "."
bool Calculator::isDotNum(const char c) {
  return isdigit(c) || c == '.';
}

// Checks if given char is one of the following: +, /, -, *, (, ).
bool Calculator::isOperator(const char c) {
  std::vector<char> operators = {'+', '-', '*', '/', '(', ')'};
  return std::find(operators.begin(), operators.end(), c) != operators.end();
}

// Checks if given string is function (like sqrt or ceil)
bool Calculator::isTextOperator(const std::string& str) {
  std::vector<std::string> operators = {"ceil", "sqrt"};
  return std::find(operators.begin(), operators.end(), str) != operators.end();
}

std::vector<std::string> Calculator::tokenizeExpression(const std::string &str) {
  std::vector<std::string> result{};
  auto i = str.begin();

  while (i != str.end()) {
    if (!isSpace(*i)) {

      if (std::isdigit(*i)) {
        auto j = std::find_if_not(i+1, str.end(), isDotNum);
        result.emplace_back(i, j);
        i = j;

      } else if (isDotNum(*i)) {
        result.push_back({*i});
        ++i;

      } else if (isalpha(*i)) {
        auto j = std::find_if_not(i+1, str.end(), isalpha);
        if (isTextOperator({i, j})) {
          result.emplace_back(i, j);
          i = j;
        } else {
          // TODO Exception
//          std::cerr << "Unexpected symbol: " << std::string(i, j) << std::endl;
          break;
        }

      } else {
        // TODO Exception
//        std::cerr << "Unexpected symbol: " << *i << std::endl;
        break;
      }
    } else {
      ++i;
    }
  }

  return result;
}

std::unique_ptr<ICalculatable> Calculator::buildTree(const std::vector<std::string> &tokens) {
  return nullptr;
}