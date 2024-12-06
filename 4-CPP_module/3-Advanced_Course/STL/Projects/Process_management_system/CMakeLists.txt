# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TaskManagerProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(TaskManager 
    main.cpp 
    Process_managament.cpp
)

# Include directories
target_include_directories(TaskManager PRIVATE ${CMAKE_SOURCE_DIR})
