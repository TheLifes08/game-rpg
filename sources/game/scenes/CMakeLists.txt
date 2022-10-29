set(HEADERS GameScene.h)
set(SOURCES GameScene.cpp)

add_library(game-scenes OBJECT ${SOURCES})
set_property(TARGET game-scenes PROPERTY POSITION_INDEPENDENT_CODE ON)
