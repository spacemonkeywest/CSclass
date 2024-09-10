# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(main)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source file
add_executable(run main.cpp)

