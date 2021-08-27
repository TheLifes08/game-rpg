#include "TextureManager.h"

Engine::Texture::TextureManager& Engine::Texture::TextureManager::getInstance() {
    static TextureManager textureManager;
    return textureManager;
}

bool Engine::Texture::TextureManager::loadTexture(const std::string& path, const std::string &name) {
    sf::Texture texture;

    if (name.empty() || !texture.loadFromFile(path)) {
        return false;
    }

    m_textures[name] = texture;

    return true;
}

sf::Texture& Engine::Texture::TextureManager::getTexture(const std::string &name) {
    if (m_textures.count(name) == 0) {
        throw std::invalid_argument("Wrong texture name.");
    }

    return m_textures[name];
}
