set(HEADERS MapParser.h JsonMapParser.h)
set(SOURCES JsonMapParser.cpp)

add_library(engine-io OBJECT ${HEADERS} ${SOURCES})
set_property(TARGET engine-io PROPERTY POSITION_INDEPENDENT_CODE ON)
