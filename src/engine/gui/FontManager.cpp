#include "FontManager.h"

Engine::Gui::FontManager& Engine::Gui::FontManager::getInstance() {
    static FontManager fontManager;
    return fontManager;
}

bool Engine::Gui::FontManager::loadFont(const std::string& path, const std::string& name) {
    sf::Font font;

    if (name.empty() || !font.loadFromFile(path)) {
        return false;
    }

    m_fonts[name] = font;

    return true;
}

sf::Font& Engine::Gui::FontManager::getFont(const std::string &name) {
    if (m_fonts.count(name) == 0) {
        throw std::invalid_argument("Wrong font name.");
    }

    return m_fonts[name];
}
