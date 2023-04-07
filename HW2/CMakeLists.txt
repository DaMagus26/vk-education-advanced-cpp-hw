cmake_minimum_required(VERSION 3.21)
project(HW2)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW2 calculator.cpp include/interface_calculatable.h src/calculatable.cpp include/calculatable.h src/tokenizer.cpp include/tokenizer.h)
