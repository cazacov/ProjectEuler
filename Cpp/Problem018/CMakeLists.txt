cmake_minimum_required(VERSION 3.15)
project(Problem018)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem018 problem018.cpp)

configure_file(data.txt data.txt COPYONLY)