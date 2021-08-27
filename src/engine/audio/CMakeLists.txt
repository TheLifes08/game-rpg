cmake_minimum_required(VERSION 3.16)
project(game-engine-audio)

set(SOURCES MusicManager.cpp)
add_library(game-engine-audio SHARED ${SOURCES})