cmake_minimum_required(VERSION 3.16)
project(rpg-game-scenes)

set(SOURCES GameScene.h GameScene.cpp)
add_library(rpg-game-scenes SHARED ${SOURCES})