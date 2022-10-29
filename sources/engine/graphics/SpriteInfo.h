#ifndef ENGINE_GRAPHICS_SPRITE_INFO_H
#define ENGINE_GRAPHICS_SPRITE_INFO_H

#include <string>


namespace Engine {
    namespace Graphics {
        struct SpriteInfo {
            std::string tileMapName;
            size_t offsetX;
            size_t offsetY;

            explicit SpriteInfo(size_t offsetX = 0, size_t offsetY = 0, const std::string& tileMapName = "");
        };
    }
}


#endif // ENGINE_GRAPHICS_SPRITE_INFO_H
