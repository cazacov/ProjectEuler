cmake_minimum_required(VERSION 3.15)
project(Problem011)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem011 main.cpp)

configure_file(grid.txt grid.txt COPYONLY)