#ifndef GAME_SCENES_GAME_SCENE_H
#define GAME_SCENES_GAME_SCENE_H

#include "../../engine/gui/WindowManager.h"
#include "../../engine/map/Map.h"


namespace Game {
    namespace Scenes {
        class GameScene : public Engine::Gui::Scene {
        public:
            explicit GameScene(Engine::Gui::WindowManager& manager);

            void onEvent(const sf::Event& event) override;
            void onUpdate(const sf::Time& elapsedTime) override;

        private:
            Engine::Map::Map m_map;
        };
    }
}


#endif // GAME_SCENES_GAME_SCENE_H
