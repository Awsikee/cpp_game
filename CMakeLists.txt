# CMake minimum version
cmake_minimum_required(VERSION 3.12)

# Project name
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    main.cpp
    src/characters/npc.cpp
    src/characters/villager.cpp
    # Add more source files as needed
)

# Include directories
include_directories(inc)
include_directories(src)
# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Subdirectories
add_subdirectory(inc/characters)
