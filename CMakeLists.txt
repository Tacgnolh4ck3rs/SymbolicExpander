cmake_minimum_required(VERSION 2.8.11)
project(expandExpression)
set(CMAKE_CXX_STANDARD 20)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
if(MSVC)
    message(STATUS "You are using Microsoft Visual C++ for compiling this.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
add_executable(main main.cpp)
include(GoogleTest)
# Compile googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)
#add_subdirectory(tests)
#include_directories(googletest/googletest/include)





