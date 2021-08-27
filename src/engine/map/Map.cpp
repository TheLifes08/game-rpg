#include "Map.h"
#include <iostream>

Engine::Map::Map::Map(size_t sizeX, size_t sizeY) {
    m_map.resize(sizeY, MapRow(sizeX));
}

Engine::Map::Cell& Engine::Map::Map::get(size_t x, size_t y) {
    if (m_map.size() <= y || m_map[y].row.size() <= x) {
        throw std::invalid_argument("Map out of range.");
    }
    return m_map[y].row[x];
}

Engine::Map::Map::MapRow::MapRow(size_t size) {
    row.resize(size);
}
