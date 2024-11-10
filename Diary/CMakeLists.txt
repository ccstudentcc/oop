# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DiaryManagement)

# Specify the C++ standard for all targets
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(src)  # Include the 'src' directory for all targets

# Add the pdadd executable
add_executable(pdadd src/pdadd.cpp)

# Add the pdlist executable
add_executable(pdlist src/pdlist.cpp)

# Add the pdremove executable
add_executable(pdremove src/pdremove.cpp)

# Add the pdshow executable
add_executable(pdshow src/pdshow.cpp)
