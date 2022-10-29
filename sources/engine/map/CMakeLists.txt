set(HEADERS Cell.h Map.h)
set(SOURCES Map.cpp)

add_library(engine-map OBJECT ${HEADERS} ${SOURCES})
set_property(TARGET engine-map PROPERTY POSITION_INDEPENDENT_CODE ON)
