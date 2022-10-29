cmake_minimum_required(VERSION 3.16)
project(game-engine)

add_subdirectory(audio)
add_subdirectory(common)
add_subdirectory(core)
add_subdirectory(graphics)
add_subdirectory(gui)
add_subdirectory(map)
add_subdirectory(math)

set(HEADERS Engine.h)
set(SOURCES Engine.cpp)

add_library(engine SHARED ${HEADERS} ${SOURCES}
            $<TARGET_OBJECTS:engine-audio>
            $<TARGET_OBJECTS:engine-common>
            $<TARGET_OBJECTS:engine-core>
            $<TARGET_OBJECTS:engine-graphics>
            $<TARGET_OBJECTS:engine-gui>
            $<TARGET_OBJECTS:engine-map>)
target_link_libraries(engine sfml-audio sfml-graphics sfml-system)
