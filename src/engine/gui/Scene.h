#ifndef ENGINE_GUI_SCENE_H
#define ENGINE_GUI_SCENE_H

#include <SFML/Graphics.hpp>


namespace Engine {
    namespace Gui {
        class WindowManager;

        class Scene {
        public:
            explicit Scene(WindowManager& manager);

            virtual void onEvent(const sf::Event& event) = 0;
            virtual void onUpdate(const sf::Time& elapsedTime) = 0;

        protected:
            WindowManager& m_manager;
        };
    }
}


#endif // ENGINE_GUI_SCENE_H
