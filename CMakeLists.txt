cmake_minimum_required(VERSION 3.21)
project(searchtitles)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.81.0 COMPONENTS program_options REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
add_executable(searchtitles main.cpp src/string_actions.cpp src/parse_tables.cpp src/validations.cpp include/validations.h)
target_link_libraries(searchtitles ${Boost_LIBRARIES})
