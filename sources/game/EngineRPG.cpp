#include "EngineRPG.h"
#include "scenes/GameScene.h"
#include "../engine/graphics/TextureManager.h"
#include "../engine/graphics/FontManager.h"

int Game::EngineRPG::initialize() {
    sf::RenderWindow& window = m_manager.getWindow();
    ::Engine::Graphics::TextureManager& textureManager = ::Engine::Graphics::TextureManager::getInstance();
    ::Engine::Graphics::FontManager& fontManager = ::Engine::Graphics::FontManager::getInstance();

    textureManager.loadTexture("../content/images/tiles1.png", "tiles1");
    fontManager.loadFont("../content/fonts/arial.ttf", "arial");

    window.create(sf::VideoMode(800, 600), "RPG", sf::Style::Close);
    window.setKeyRepeatEnabled(false);
    m_manager.setScene(std::make_unique<Scenes::GameScene>(m_manager));

    return 0;
}
