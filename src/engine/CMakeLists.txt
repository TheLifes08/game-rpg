cmake_minimum_required(VERSION 3.16)
project(game-engine)

add_subdirectory(audio)
add_subdirectory(common)
add_subdirectory(gui)
add_subdirectory(map)
add_subdirectory(texture)

set(SOURCES Engine.cpp)
add_library(game-engine SHARED ${SOURCES})