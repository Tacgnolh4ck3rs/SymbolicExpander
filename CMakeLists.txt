cmake_minimum_required(VERSION 2.8.11)
project(expandExpression)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
if (MSVC)
    message(STATUS "You are using Microsoft Visual C++ for compiling this.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()


set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
add_executable(main main.cpp)
include(GoogleTest)
include_directories(googletest/googletest/include)
#add_subdirectory(googletest)
#add_subdirectory(tests)

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
