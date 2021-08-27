#ifndef ENGINE_MAP_CELL_H
#define ENGINE_MAP_CELL_H

#include <string>


namespace Engine {
    namespace Map {
        struct Cell {
            std::string tileMapName;
            size_t offsetX;
            size_t offsetY;
        };
    }
}


#endif // ENGINE_MAP_CELL_H
