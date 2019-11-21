cmake_minimum_required(VERSION 3.12)
project(Problem059)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem059 problem059.cpp)
configure_file(cipher.txt cipher.txt COPYONLY)