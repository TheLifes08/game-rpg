cmake_minimum_required(VERSION 3.16)
project(game-engine-object)

set(SOURCES Object.cpp Creature.cpp)
add_library(game-engine-object SHARED ${SOURCES})
