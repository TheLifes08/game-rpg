#ifndef ENGINE_OBJECT_OBJECT_H
#define ENGINE_OBJECT_OBJECT_H

#include "../common/Vector2D.h"
#include <SFML/Graphics.hpp>


namespace Engine {
    namespace Object {
        class Object {
        public:
            explicit Object();
            explicit Object(const std::string& tileMapName);
            Object(const std::string& tileMapName, const Common::Position& position);
            virtual ~Object() = default;

            virtual void onInteraction(const Object&);
            virtual void onUpdate(const sf::Time& elapsedTime);
            void setSolid(bool value);
            bool getSolid() const;
            Common::Position& position();
            Common::Velocity& velocity();
            sf::Sprite& sprite();

        protected:
            Common::Position m_position;
            Common::Velocity m_velocity;
            sf::Sprite m_sprite;
            bool m_solid;
        };
    }
}


#endif // ENGINE_OBJECT_OBJECT_H
