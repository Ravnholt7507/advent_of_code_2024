# Minimum CMake version
cmake_minimum_required(VERSION 3.16)

# Project name and language
project(output LANGUAGES CXX)

# Enable the generation of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic-errors -g")

# Source files
file(GLOB SRCS "main.cpp" "*December/solution.cpp")
file(GLOB HEADERS "*December/solution.h")

# Add executable
add_executable(${PROJECT_NAME} ${SRCS})

# Include directories if needed (for headers)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

# Clean target (optional, requires enabling custom commands)
set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM TRUE)
