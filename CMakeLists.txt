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
    src/game/textureManager.cpp
    src/game/GameObject.cpp
    src/game/Map.cpp
    src/game/Vector2D.cpp
    src/game/Collision.cpp



    # Add more source files as needed
)

# Include directories
include_directories(inc)
include_directories(src)
include_directories(SDL2_image-2.8.1)

# Find SDL2
set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc/lib/cmake/SDL2)
set(SDL2_IMAGE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2_image-2.8.1/SDL_IMAGE/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS} SDL2_image::SDL2_image )
# Link with SDL2
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SDL2_image::SDL2_image)

# Subdirectories
add_subdirectory(inc/characters)
add_subdirectory(inc/buildings)
