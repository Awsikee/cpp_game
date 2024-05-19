# CMake minimum version
cmake_minimum_required(VERSION 3.12)

# Project name
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
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
    src/game/ECS.cpp
    # Add more source files as needed
)

# Include directories
include_directories(
    inc
    src
    SDL2_image-2.8.2/include
    SDL2_image-2.30.1/include  
)

# Find SDL2 and SDL2_image
set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2-2.30.1/cmake)  
set(SDL2_IMAGE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2_image-2.8.2/cmake)  

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link with SDL2 and SDL2_image
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SDL2_image::SDL2_image)
add_subdirectory(inc/characters)
add_subdirectory(inc/buildings)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DIR}/../lib/x64/SDL2.dll"
        "${CMAKE_BINARY_DIR}/SDL2.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_IMAGE_DIR}/../lib/x64/SDL2_image.dll"
        "${CMAKE_BINARY_DIR}/SDL2_image.dll"
    # Add other DLLs as needed
)
