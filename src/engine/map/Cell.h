#ifndef ENGINE_MAP_CELL_H
#define ENGINE_MAP_CELL_H

#include "../graphics/SpriteInfo.h"


namespace Engine {
    namespace Map {
        struct Cell {
            static const size_t cellSizeX = 64;
            static const size_t cellSizeY = 64;

            Graphics::SpriteInfo spriteInfo;
            bool solid = false;
        };
    }
}


#endif // ENGINE_MAP_CELL_H
