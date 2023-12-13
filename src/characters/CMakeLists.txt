# inc/characters/CMakeLists.txt
# Include the header files in the characters folder
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add the source files for the characters library
set(CHARACTERS_SOURCES
    npc.cpp
    # Add more source files as needed
)

# Create a library from the sources
add_library(characters_lib ${CHARACTERS_SOURCES})