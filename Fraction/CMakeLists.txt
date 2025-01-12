cmake_minimum_required(VERSION 3.10)

project(FractionProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/test.cpp
    src/Fraction.cpp
)

add_executable(FractionTest ${SOURCES})