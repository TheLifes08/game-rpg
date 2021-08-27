cmake_minimum_required(VERSION 3.16)
project(game-engine-texture)

set(SOURCES TextureManager.cpp)
add_library(game-engine-texture SHARED ${SOURCES})