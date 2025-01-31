cmake_minimum_required(VERSION 2.8.11)
project(expandExpression)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
if (MSVC)
    message(STATUS "You are using Microsoft Visual C++ for compiling this.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    link_directories(C:/Users/sisco/AppData/Local/Programs/Python/Python39/libs)
elseif (UNIX AND CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")
endif()

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
message(STATUS "Include dir")
message(STATUS ${Python3_INCLUDE_DIRS})

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
add_executable(main main.cpp solve.hpp)
include(GoogleTest)
include_directories(googletest/googletest/include)
include_directories(${Python3_INCLUDE_DIRS})
include_directories(pybind11/include)
add_subdirectory(pybind11)
target_link_libraries(main PUBLIC pybind11::embed)
add_subdirectory(googletest)
add_subdirectory(tests)

# Doxygen snippet
option(BUILD_DOC "Build documentation" ON)
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    # Configure in and out
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen is building the docs")
    add_custom_target(dox_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating app docs with Doxygen"
        VERBATIM)
else (DOXYGEN_FOUND)
    message("Doxygen is not installed, could not generate docs")
endif (DOXYGEN_FOUND)

set( FILES_DIR
    ${CMAKE_SOURCE_DIR}/config.json
    ${CMAKE_SOURCE_DIR}/expandUtils.py)

foreach( file_i ${FILES_DIR})
    add_custom_command(
    TARGET main
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy ${file_i} ${CMAKE_CURRENT_BINARY_DIR})
endforeach( file_i )
