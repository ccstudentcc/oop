# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DiaryManagement)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the pdadd executable
add_executable(pdadd src/pdadd.cpp)
target_include_directories(pdadd PRIVATE src)

# Add the pdlist executable
add_executable(pdlist src/pdlist.cpp)
target_include_directories(pdlist PRIVATE src)

# Add the pdremove executable
add_executable(pdremove src/pdremove.cpp)
target_include_directories(pdremove PRIVATE src)

# Add the pdshow executable
add_executable(pdshow src/pdshow.cpp)
target_include_directories(pdshow PRIVATE src)
