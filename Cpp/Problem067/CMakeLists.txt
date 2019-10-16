cmake_minimum_required(VERSION 3.15)
project(Problem067)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem067 problem067.cpp)
configure_file(p067_triangle.txt p067_triangle.txt COPYONLY)