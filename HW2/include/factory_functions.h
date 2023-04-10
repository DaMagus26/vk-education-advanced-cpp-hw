#pragma once
#include "../include/interface_calculatable.h"
#include <memory>
#include <stack>

using factoryFunction = void (*)(std::stack<std::unique_ptr<ICalculatable>>&);

void createAdd(std::stack<std::unique_ptr<ICalculatable>>&);
void createSub(std::stack<std::unique_ptr<ICalculatable>>&);
void createMul(std::stack<std::unique_ptr<ICalculatable>>&);
void createSqrt(std::stack<std::unique_ptr<ICalculatable>>&);
void createCeil(std::stack<std::unique_ptr<ICalculatable>>&);