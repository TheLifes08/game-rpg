#ifndef ENGINE_MAP_MAP_H
#define ENGINE_MAP_MAP_H

#include "Cell.h"
#include <engine/common/Types.h>
#include <engine/core/Object.h>
#include <istream>
#include <vector>


namespace Engine {
    namespace Map {
        class Map {
        public:
            Map();
            Map(size_t sizeX, size_t sizeY);

            Cell& get(size_t x, size_t y);
            Cell& get(double x, double y);
            std::vector<Core::Object>& getObjects();
            bool loadMap(std::istream& dataStream);
            Common::Size getSize();


        private:
            struct MapRow {
                std::vector<Cell> row;
                explicit MapRow(size_t size);
            };

            Common::Size m_size;
            std::vector<MapRow> m_rows;
            std::vector<Core::Object> m_objects;
            Cell m_outboundCell;
        };
    }
}


#endif // ENGINE_MAP_MAP_H
