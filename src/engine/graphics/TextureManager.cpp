#include "TextureManager.h"

Engine::Graphics::TextureManager& Engine::Graphics::TextureManager::getInstance() {
    static TextureManager textureManager;
    return textureManager;
}

bool Engine::Graphics::TextureManager::loadTexture(const std::string& path, const std::string &name) {
    sf::Texture texture;

    if (name.empty() || !texture.loadFromFile(path)) {
        return false;
    }

    m_textures[name] = texture;

    return true;
}

sf::Texture& Engine::Graphics::TextureManager::getTexture(const std::string& name) {
    if (m_textures.count(name) == 0) {
        throw std::invalid_argument("Wrong texture name: " + name);
    }

    return m_textures[name];
}
