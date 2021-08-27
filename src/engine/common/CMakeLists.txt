cmake_minimum_required(VERSION 3.16)
project(game-engine-common)

set(SOURCES Exception.cpp)
add_library(game-engine-common SHARED ${SOURCES})