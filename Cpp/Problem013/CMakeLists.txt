cmake_minimum_required(VERSION 3.15)
project(Problem013)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem013 problem013.cpp cmake-build-debug/BigNatural.cpp cmake-build-debug/BigNatural.h)

configure_file(numbers.txt numbers.txt COPYONLY)