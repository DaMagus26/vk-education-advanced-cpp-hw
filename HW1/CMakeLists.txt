cmake_minimum_required(VERSION 3.21)
project(searchtitles)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(searchtitles main.cpp src/string_actions.cpp src/parse_tables.cpp src/validations.cpp src/argparse.cpp src/output.cpp)
