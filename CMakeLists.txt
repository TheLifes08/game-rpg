cmake_minimum_required(VERSION 3.16)
project(sfml-rpg-game)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_subdirectory(src/engine)
add_subdirectory(src/game)

set(SOURCES src/main.cpp)
add_executable(sfml-rpg-game ${SOURCES})
link_libraries(game-engine rpg-game)
target_link_libraries(sfml-rpg-game game-engine rpg-game sfml-graphics sfml-audio)

file(COPY "resources" DESTINATION ".")