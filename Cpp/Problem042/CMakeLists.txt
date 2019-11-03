cmake_minimum_required(VERSION 3.15)
project(Problem042)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem042 problem042.cpp)

configure_file(p042_words.txt words.txt COPYONLY)