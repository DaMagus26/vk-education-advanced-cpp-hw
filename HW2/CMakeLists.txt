cmake_minimum_required(VERSION 3.21)
project(HW2)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW2 main.cpp include/operations.h src/operations.cpp src/calculator.cpp include/calculator.h include/calc_exception.h)