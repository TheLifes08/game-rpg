#include "EngineRPG.h"
#include "scenes/GameScene.h"
#include "../engine/audio/MusicManager.h"
#include "../engine/texture/TextureManager.h"

int Game::EngineRPG::initialize() {
    sf::RenderWindow& window = m_manager.getWindow();
    ::Engine::Audio::MusicManager& musicManager = ::Engine::Audio::MusicManager::getInstance();
    ::Engine::Texture::TextureManager& textureManager = ::Engine::Texture::TextureManager::getInstance();

    textureManager.loadTexture("resources/tiles1.png", "tiles1");

    window.create(sf::VideoMode(800, 600), "RPG", sf::Style::Close);
    m_manager.setScene(std::make_unique<Scenes::GameScene>(m_manager));

    return 0;
}
