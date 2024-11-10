# Updated CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(Adventure)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/room.cpp
    src/player.cpp
    src/init.cpp
)

# Include GoogleTest
enable_testing()
set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/googletest")
add_subdirectory(${GTEST_ROOT} ${CMAKE_BINARY_DIR}/googletest-build)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Game executable
add_executable(adventure src/adventure.cpp ${SOURCES})

# Test executable
add_executable(test_adventure test/test_adventure.cpp ${SOURCES})
target_link_libraries(test_adventure gtest gtest_main)

# Add a test
add_test(NAME adventure_tests COMMAND test_adventure)
