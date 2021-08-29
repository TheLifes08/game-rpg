#include "Map.h"
#include <iostream>

Engine::Map::Map::Map(): m_size(0, 0) {}

Engine::Map::Map::Map(size_t sizeX, size_t sizeY): m_size(sizeX, sizeY) {
    m_rows.resize(sizeY, MapRow(sizeX));
}

Engine::Map::Cell& Engine::Map::Map::get(size_t x, size_t y) {
    if (m_rows.size() <= y || m_rows[y].row.size() <= x) {
        throw std::invalid_argument("Map out of range.");
    }
    return m_rows[y].row[x];
}

std::vector<Engine::Object::Object>& Engine::Map::Map::getObjects() {
    return m_objects;
}

bool Engine::Map::Map::loadMap(std::istream& dataStream) {
    try {
        size_t mapWidth, mapHeight, offsetX, offsetY, type;
        std::string tileMapName;

        dataStream >> mapWidth >> mapHeight >> tileMapName;

        m_rows.clear();
        m_rows.resize(mapHeight, MapRow(mapWidth));
        m_size = Common::Size(mapWidth, mapHeight);

        for (size_t y = 0; y < mapHeight; ++y) {
            for (size_t x = 0; x < mapWidth; ++x) {
                Cell& cell = get(x, y);

                dataStream >> offsetX >> offsetY >> type;

                cell.spriteInfo.tileMapName = tileMapName;
                cell.spriteInfo.offsetX = offsetX;
                cell.spriteInfo.offsetY = offsetY;
                cell.solid = type != 0;
            }
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }

    return true;
}

Engine::Common::Size Engine::Map::Map::getSize() {
    return m_size;
}

Engine::Map::Map::MapRow::MapRow(size_t size) {
    row.resize(size);
}
