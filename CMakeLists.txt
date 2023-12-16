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
    src/buildings/building.cpp
    src/buildings/smallHouse.cpp
    src/game/game.cpp


    # Add more source files as needed
)

# Include directories
include_directories(inc)
include_directories(src)

# Find SDL2
set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc/lib/cmake/SDL2)
find_package(SDL2 REQUIRED)

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link with SDL2
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main)

# Subdirectories
add_subdirectory(inc/characters)
