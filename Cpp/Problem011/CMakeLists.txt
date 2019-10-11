cmake_minimum_required(VERSION 3.15)
project(Problem011)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem011 Problem011.cpp)

configure_file(grid.txt grid.txt COPYONLY)