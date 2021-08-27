#include "GameScene.h"
#include "../../engine/texture/TextureManager.h"
#include <iostream>

Game::Scenes::GameScene::GameScene(Engine::Gui::WindowManager& manager) : Scene(manager), m_map(10, 10) {
    for (size_t y = 0; y < 10; ++y) {
        for (size_t x = 0; x < 10; ++x) {
            Engine::Map::Cell& cell = m_map.get(x, y);
            cell.offsetX = 64;
            cell.offsetY = 0;
            cell.tileMapName = "tiles1";
        }
    }

}

void Game::Scenes::GameScene::onEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        sf::View view = m_manager.getWindow().getView();

        if (event.key.code == sf::Keyboard::Right) {
            view.setCenter(view.getCenter().x + 10, view.getCenter().y);
        } else if (event.key.code == sf::Keyboard::Left) {
            view.setCenter(view.getCenter().x - 10, view.getCenter().y);
        } else if (event.key.code == sf::Keyboard::Up) {
            view.setCenter(view.getCenter().x, view.getCenter().y - 10);
        } else if (event.key.code == sf::Keyboard::Down) {
            view.setCenter(view.getCenter().x, view.getCenter().y + 10);
        }

        m_manager.getWindow().setView(view);
    }
}

void Game::Scenes::GameScene::onUpdate(const sf::Time& elapsedTime) {


    ::Engine::Texture::TextureManager& textureManager = ::Engine::Texture::TextureManager::getInstance();
    sf::RenderWindow& window = m_manager.getWindow();
    window.clear();

    sf::Texture& texture = textureManager.getTexture("tiles1");
    sf::Sprite sprite(texture);

    for (size_t y = 0; y < 10; ++y) {
        for (size_t x = 0; x < 10; ++x) {
            Engine::Map::Cell& cell = m_map.get(x, y);
            std::cerr << x << " " << y << "\n";
            sprite.setPosition(64 * x, 64 * y);
            sprite.setTextureRect(sf::IntRect(cell.offsetX, cell.offsetY, 64, 64));
            window.draw(sprite);
        }
    }

    window.display();
}
