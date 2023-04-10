cmake_minimum_required(VERSION 3.21)
project(HW2)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW2 main.cpp src/calculator.cpp include/calculator.h include/calc_exception.h
        include/operations/number.h src/opreations/number.cpp
        include/operations/add.h src/opreations/add.cpp
        include/operations/sub.h src/opreations/sub.cpp
        include/operations/mul.h src/opreations/mul.cpp
        include/operations/sqrt.h src/opreations/sqrt.cpp
        include/operations/ceil.h src/opreations/ceil.cpp
        include/factory_functions.h src/factory_functions.cpp)