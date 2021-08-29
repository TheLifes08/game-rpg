cmake_minimum_required(VERSION 3.16)
project(rpg-game)

add_subdirectory(scenes)

set(SOURCES EngineRPG.cpp ../engine/gui/Scene.cpp ../engine/gui/WindowManager.cpp ../engine/common/Exception.cpp scenes/GameScene.cpp
        ../engine/graphics/TextureManager.cpp ../engine/audio/MusicManager.cpp ../engine/map/Map.cpp ../engine/object/Object.cpp
        ../engine/graphics/SpriteInfo.cpp ../engine/graphics/FontManager.cpp ../engine/object/Creature.cpp)
add_library(rpg-game SHARED ${SOURCES})