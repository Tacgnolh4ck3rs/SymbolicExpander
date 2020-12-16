cmake_minimum_required(VERSION 3.10)
project(test VERSION 1.0)
# Secondary CMakeLists.txt, which is placed
# under tests folder. This would load the googletest
# and build it as well. Even more, it would compiles
# the tests needed.
# Use Google Test special commands such as
# gtest_discover_tests
include(GoogleTest)
# Set the variable ${This} to the value "test"
set(This test)
# Print a message
message(STATUS "Cmake source dir is ${CMAKE_SOURCE_DIR}")
# Add google test build to project
# This set below is needed for Windows builds
if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
# Create test executable file
add_executable(${This} mainTests.cpp)
# Set gtest_main for linking with the executable file
# using _main means that we do not need to specify a 
# int main(...) function at our mainTests.cpp
target_link_libraries(${This} PUBLIC gtest_main)
# Look for tests at the file
gtest_discover_tests(${This})

