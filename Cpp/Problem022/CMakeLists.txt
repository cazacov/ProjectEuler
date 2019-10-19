cmake_minimum_required(VERSION 3.15)
project(Problem022)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem022 problem022.cpp)

configure_file(p022_names.txt p022_names.txt COPYONLY)