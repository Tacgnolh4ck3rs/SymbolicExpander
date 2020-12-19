cmake_minimum_required(VERSION 3.10)
project(integrateCalculator VERSION 1.0)
# Main CMakeLists.txt, which is placed at the root folder
set(CMAKE_CXX_STANDARD 20)
# If we are in window$
if (MSVC)
    add_compile_options(/bigobj)
endif()
# Create main executable
add_executable(main main.cpp)
# Do not build GMock
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/googletest)
include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)
# Look for CMakeLists.txt under the tests directory
add_subdirectory(tests)

if (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
    # build the docs
endif()