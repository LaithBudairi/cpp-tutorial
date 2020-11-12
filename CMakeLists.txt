# cmake_minimum_required(VERSION <specify CMake version here>)
project(cpp_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_tutorial main.cpp add/test.h add/test.cpp mainalternatives/cppfiles/mymain.cpp mainalternatives/headers/mymain.h mainalternatives/cppfiles/variables.cpp mainalternatives/headers/variables.h mainalternatives/cppfiles/arrays.cpp mainalternatives/headers/arrays.h mainalternatives/cppfiles/pointers.cpp mainalternatives/headers/pointers.h mainalternatives/cppfiles/functions.cpp mainalternatives/headers/functions.h)