cmake_minimum_required(VERSION 3.16)
project(sfml-rpg-game)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
find_package(nlohmann_json)

include_directories(sources)

add_subdirectory(sources/engine)
add_subdirectory(sources/game)

add_executable(rpg-game sources/main.cpp)
target_link_libraries(rpg-game engine game)

file(COPY "content" DESTINATION ".")