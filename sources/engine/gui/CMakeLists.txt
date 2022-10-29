set(HEADERS Scene.h WindowManager.h)
set(SOURCES Scene.cpp WindowManager.cpp)

add_library(engine-gui OBJECT ${HEADERS} ${SOURCES})
set_property(TARGET engine-gui PROPERTY POSITION_INDEPENDENT_CODE ON)
