add_subdirectory(scenes)

set(SOURCES EngineRPG.cpp)

add_library(game SHARED ${SOURCES} $<TARGET_OBJECTS:game-scenes>)
