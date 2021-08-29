cmake_minimum_required(VERSION 3.16)
project(game-engine-graphics)

set(SOURCES TextureManager.cpp SpriteInfo.cpp FontManager.cpp)
add_library(game-engine-graphics SHARED ${SOURCES})