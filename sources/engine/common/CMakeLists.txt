set(HEADERS Exception.h)
set(SOURCES Exception.cpp)

add_library(engine-common OBJECT ${HEADERS} ${SOURCES})
set_property(TARGET engine-common PROPERTY POSITION_INDEPENDENT_CODE ON)
