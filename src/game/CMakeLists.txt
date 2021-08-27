cmake_minimum_required(VERSION 3.16)
project(rpg-game)

add_subdirectory(scenes)

set(SOURCES EngineRPG.cpp ../engine/gui/Scene.cpp ../engine/gui/WindowManager.cpp ../engine/common/Exception.cpp scenes/GameScene.cpp
        ../engine/texture/TextureManager.cpp ../engine/audio/MusicManager.cpp ../engine/map/Map.cpp)
add_library(rpg-game SHARED ${SOURCES})