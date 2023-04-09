#include "../include/calculator.h"
#include "../include/calc_exception.h"
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <regex>

Calculator::Calculator(const std::string &str) {
  if (str.empty()) {
    root = nullptr;
    return;
  }

  std::vector<std::string> tokens = tokenizeExpression(str);
  std::vector<std::string> postfix = postfixNotation(tokens);
  root = buildTree(postfix);
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

bool Calculator::isValidDouble(const std::string &op) {
  std::regex double_pattern{"[-+]?[0-9]*\\.?[0-9]+"};
  return std::regex_match(op.begin(), op.end(), double_pattern);
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

      } else if (isOperator(*i)) {
        result.push_back({*i});
        ++i;

      } else if (isalpha(*i)) {
        auto j = std::find_if_not(i+1, str.end(), isalpha);
        if (isTextOperator({i, j})) {
          result.emplace_back(i, j);
          i = j;
        } else {
          throw ParseError("Unexpected symbol: " + std::string(i, j));
        }

      } else {
        throw ParseError(&"Unexpected symbol: " [ *i]);
      }
    } else {
      ++i;
    }
  }

  return result;
}

std::vector<std::string> Calculator::postfixNotation(const std::vector<std::string> &tokens) {
  std::vector<std::string> postfix;
  std::stack<std::string> opStack;
  std::map<std::string, int> precedence = {
      {"(", 0},
      {")", 0},
      {"+", 1},
      {"-", 1},
      {"*", 2},
      {"sqrt", 3},
      {"ceil", 3}
  };

  for (const std::string& token : tokens) {
    if (precedence.count(token) == 0) { // Operand
      postfix.push_back(token);
    } else if (token == "(") { // Opening parenthesis
      opStack.push(token);
    } else if (token == ")") { // Closing parenthesis
      while (!opStack.empty() && opStack.top() != "(") {
        postfix.push_back(opStack.top());
        opStack.pop();
      }
      if (!opStack.empty() && opStack.top() == "(") {
        opStack.pop();
      }
    } else { // Operator
      while (!opStack.empty() && precedence[opStack.top()] >= precedence[token]) {
        postfix.push_back(opStack.top());
        opStack.pop();
      }
      opStack.push(token);
    }
  }

  while (!opStack.empty()) {
    postfix.push_back(opStack.top());
    opStack.pop();
  }

  return postfix;
}

std::unique_ptr<ICalculatable> Calculator::buildTree(const std::vector<std::string> &tokens) {
  std::stack<std::unique_ptr<ICalculatable>> stack;

  for (const auto& token : tokens) {
    if (isValidDouble(token)) {
      stack.push(std::make_unique<Number>(std::stod(token)));
    } else {
      if (token == "+") {
        auto right = std::move(stack.top());
        stack.pop();
        auto left = std::move(stack.top());
        stack.pop();
        stack.push(std::make_unique<Add>(*left, *right));

      } else if (token == "-") {
        auto right = std::move(stack.top());
        stack.pop();
        auto left = std::move(stack.top());
        stack.pop();
        stack.push(std::make_unique<Sub>(*left, *right));

      } else if (token == "*") {
        auto right = std::move(stack.top());
        stack.pop();
        auto left = std::move(stack.top());
        stack.pop();
        stack.push(std::make_unique<Mul>(*left, *right));

      } else if (token == "sqrt") {
        auto right = std::move(stack.top());
        stack.pop();
        stack.push(std::make_unique<Sqrt>(*right));

      } else if (token == "ceil") {
        auto right = std::move(stack.top());
        stack.pop();
        stack.push(std::make_unique<Ceil>(*right));

      }
    }
  }

  return std::move(stack.top());
}
