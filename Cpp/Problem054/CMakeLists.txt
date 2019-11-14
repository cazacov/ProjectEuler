cmake_minimum_required(VERSION 3.12)
project(Problem054)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem054 problem054.cpp PokerRules.cpp PokerRules.h)
configure_file(poker.txt poker.txt COPYONLY)