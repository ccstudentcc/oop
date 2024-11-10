cmake_minimum_required(VERSION 3.10)

project(StudentProgram)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/student.cpp
    src/utils.cpp
)

add_executable(student_program ${SOURCES})