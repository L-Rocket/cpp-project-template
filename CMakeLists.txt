cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(test src/main.cpp src/example.cpp)

add_executable(test_main tests/test_main.cpp src/example.cpp)