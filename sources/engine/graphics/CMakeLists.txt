set(HEADERS FontManager.h SpriteInfo.h TextureManager.h)
set(SOURCES TextureManager.cpp SpriteInfo.cpp FontManager.cpp)

add_library(engine-graphics OBJECT ${HEADERS} ${SOURCES})
set_property(TARGET engine-graphics PROPERTY POSITION_INDEPENDENT_CODE ON)
