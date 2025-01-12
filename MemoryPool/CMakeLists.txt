cmake_minimum_required(VERSION 3.10)
project(MemoryPool VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Release mode with O2 optimization
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Ignore warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")

# Add executable
add_executable(test src/test.cpp)