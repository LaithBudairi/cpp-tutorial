# cmake_minimum_required(VERSION <specify CMake version here>)
project(cpp_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_tutorial main.cpp add/test.h add/test.cpp)