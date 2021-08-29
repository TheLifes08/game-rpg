cmake_minimum_required(VERSION 3.16)
project(game-engine-gui)

set(SOURCES Scene.cpp WindowManager.cpp)
add_library(game-engine-gui SHARED ${SOURCES})
