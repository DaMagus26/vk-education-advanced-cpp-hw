#include <vector>
#include <algorithm>
#include <iostream>

#include <stack>
#include <queue>
#include <cstdlib>

bool isSpace(const char c) {
  return c == ' ';
}

// Checks is given character is a digit or "."
bool isOperand(const char c) {
  return isdigit(c) || c == '.';
}

// Checks if given char is one of the following: +, /, -, *, (, ).
bool isOperator(const char c) {
  std::vector<char> operators = {'+', '-', '*', '/', '(', ')'};
  return std::find(operators.begin(), operators.end(), c) != operators.end();
}

// Checks if given string is function (like sqrt or ceil)
bool isTextOperator(const std::string& str) {
  std::vector<std::string> operators = {"ceil", "sqrt"};
  return std::find(operators.begin(), operators.end(), str) != operators.end();
}

std::vector<std::string> tokenizeExpressionString(const std::string &str) {
  std::vector<std::string> result{};
  auto i = str.begin();

  while (i != str.end()) {
    if (!isSpace(*i)) {

      if (std::isdigit(*i)) {
        auto j = std::find_if_not(i+1, str.end(), isOperand);
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
          // TODO Exception
          std::cerr << "Unexpected symbol: " << std::string(i, j) << std::endl;
          break;
        }

      } else {
        // TODO Exception
        std::cerr << "Unexpected symbol: " << *i << std::endl;
        break;
      }
    } else {
      ++i;
    }
  }

  return result;
}

bool isValidOperand(const std::string& op) {
  // FIXME
  if (op.empty()) {
    return false;
  }

  char* end_ptr;
  double result = strtod(op.c_str(), &end_ptr);
  return !(op.c_str() == end_ptr && result == 0.0);
}

double solver(const std::vector<std::string>& tokens) {
  std::stack<std::string> operators;
  std::queue<double> operands;
  for (const auto& token: tokens) {
    if (isValidOperand(token)) {
      char* end_ptr;
      double result = strtod(token.c_str(), &end_ptr);
      operands.push(result);
    } else if (token == "(") {
      operators.push(token);
    }
  }
  return 0;
}