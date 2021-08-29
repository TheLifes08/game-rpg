#ifndef ENGINE_MAP_MAP_H
#define ENGINE_MAP_MAP_H

#include "Cell.h"
#include "../common/Vector2D.h"
#include "../object/Object.h"
#include <istream>
#include <vector>


namespace Engine {
    namespace Map {
        class Map {
        public:
            Map();
            Map(size_t sizeX, size_t sizeY);

            Cell& get(size_t x, size_t y);
            std::vector<Object::Object>& getObjects();
            bool loadMap(std::istream& dataStream);
            Common::Size getSize();


        private:
            struct MapRow {
                std::vector<Cell> row;
                explicit MapRow(size_t size);
            };

            Common::Size m_size;
            std::vector<MapRow> m_rows;
            std::vector<Object::Object> m_objects;
        };
    }
}


#endif // ENGINE_MAP_MAP_H
