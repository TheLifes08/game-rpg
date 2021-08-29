#include "Object.h"
#include "../graphics/TextureManager.h"

Engine::Object::Object::Object()
: Object("none", {0, 0}) {}

Engine::Object::Object::Object(const std::string& tileMapName)
: Object(tileMapName, {0, 0}) {}

Engine::Object::Object::Object(const std::string& tileMapName, const Engine::Common::Position& position)
: m_position(position), m_velocity(0, 0), m_solid(true) {
    Graphics::TextureManager& textureManager = Graphics::TextureManager::getInstance();

    try {
        sf::Texture& texture = textureManager.getTexture(tileMapName);
        m_sprite.setTexture(texture);
    } catch (const std::invalid_argument& e) {
        // do nothing
    }
}

void Engine::Object::Object::onInteraction(const Engine::Object::Object &) {
    // Do nothing
}

void Engine::Object::Object::onUpdate(const sf::Time &elapsedTime) {
    m_position.x += m_velocity.x * elapsedTime.asSeconds();
    m_position.y += m_velocity.y * elapsedTime.asSeconds();
}

void Engine::Object::Object::setSolid(bool value) {
    m_solid = value;
}

bool Engine::Object::Object::getSolid() const {
    return m_solid;
}

Engine::Common::Position& Engine::Object::Object::position() {
    return m_position;
}

sf::Sprite& Engine::Object::Object::sprite() {
    return m_sprite;
}

Engine::Common::Velocity &Engine::Object::Object::velocity() {
    return m_velocity;
}
