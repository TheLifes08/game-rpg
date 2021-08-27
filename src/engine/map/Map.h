#ifndef ENGINE_MAP_MAP_H
#define ENGINE_MAP_MAP_H

#include "Cell.h"
#include <vector>


namespace Engine {
    namespace Map {
        class Map {
        public:
            Map(size_t sizeX, size_t sizeY);

            Cell& get(size_t x, size_t y);

        private:
            struct MapRow {
                std::vector<Cell> row;
                explicit MapRow(size_t size);
            };

            std::vector<MapRow> m_map;
        };
    }
}


#endif // ENGINE_MAP_MAP_H
