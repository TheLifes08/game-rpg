#ifndef ENGINE_GRAPHICS_FONT_MANAGER_H
#define ENGINE_GRAPHICS_FONT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>


namespace Engine::Graphics {
        class FontManager {
        public:
            FontManager(const FontManager&) = delete;
            FontManager(FontManager&&) = delete;
            FontManager& operator=(const FontManager&) = delete;
            FontManager& operator=(FontManager&&) = delete;

            static FontManager& getInstance();
            bool loadFont(const std::string& path, const std::string& name);
            sf::Font& getFont(const std::string& name);

        private:
            FontManager() = default;

            std::map<std::string, sf::Font> m_fonts;
        };
    }


#endif // ENGINE_GRAPHICS_FONT_MANAGER_H
