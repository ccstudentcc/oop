cmake_minimum_required(VERSION 3.10)

project(VectorProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/test.cpp
)

add_executable(VectorTest ${SOURCES})