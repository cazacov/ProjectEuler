cmake_minimum_required(VERSION 3.15)
project(Problem017)

set(CMAKE_CXX_STANDARD 14)

add_executable(Problem017 problem017.cpp NumberSpeller.cpp NumberSpeller.h)
#add_executable(Problem017 NumberSpeller.cpp NumberSpeller.h NumberSpellerTests.cpp NumberSpellerTests.h)