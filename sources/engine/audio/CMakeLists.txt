set(HEADERS AudioManager.h)
set(SOURCES AudioManager.cpp)

add_library(engine-audio OBJECT ${HEADERS} ${SOURCES})
set_property(TARGET engine-audio PROPERTY POSITION_INDEPENDENT_CODE ON)
