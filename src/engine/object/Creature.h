#ifndef ENGINE_OBJECT_CREATURE_H
#define ENGINE_OBJECT_CREATURE_H

#include "Object.h"


namespace Engine {
    namespace Object {
        class Creature : public Object {
        public:
            explicit Creature(const std::string& tileMapName);
            Creature(const std::string& tileMapName, const Common::Position& position);

            void onInteraction(const Object &) override;
        };
    }
}


#endif // ENGINE_OBJECT_CREATURE_H
