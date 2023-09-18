#include "../include/factory_functions.h"
#include "../include/operations/number.h"
#include "../include/operations/add.h"
#include "../include/operations/sub.h"
#include "../include/operations/mul.h"
#include "../include/operations/sqrt.h"
#include "../include/operations/ceil.h"
#include <memory>
#include <stack>

void createAdd(std::stack<std::unique_ptr<ICalculatable>>& stack) {
  auto right = std::move(stack.top());
  stack.pop();
  auto left = std::move(stack.top());
  stack.pop();
  stack.push(std::make_unique<Add>(*left, *right));
}

void createSub(std::stack<std::unique_ptr<ICalculatable>>& stack) {
  auto right = std::move(stack.top());
  stack.pop();
  auto left = std::move(stack.top());
  stack.pop();
  stack.push(std::make_unique<Sub>(*left, *right));
}

void createMul(std::stack<std::unique_ptr<ICalculatable>>& stack) {
  auto right = std::move(stack.top());
  stack.pop();
  auto left = std::move(stack.top());
  stack.pop();
  stack.push(std::make_unique<Mul>(*left, *right));
}

void createSqrt(std::stack<std::unique_ptr<ICalculatable>>& stack) {
  auto right = std::move(stack.top());
  stack.pop();
  stack.push(std::make_unique<Sqrt>(*right));
}

void createCeil(std::stack<std::unique_ptr<ICalculatable>>& stack) {
  auto right = std::move(stack.top());
  stack.pop();
  stack.push(std::make_unique<Ceil>(*right));
}