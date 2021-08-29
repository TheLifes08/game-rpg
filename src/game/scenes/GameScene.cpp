#include "GameScene.h"
#include "../../engine/audio/MusicManager.h"
#include "../../engine/graphics/TextureManager.h"
#include "../../engine/graphics/FontManager.h"
#include <iostream>
#include <fstream>

Game::Scenes::GameScene::GameScene(Engine::Gui::WindowManager& manager)
: Scene(manager), m_player("tiles1", {1, 1}) {
    ::Engine::Audio::MusicManager& musicManager = ::Engine::Audio::MusicManager::getInstance();

    musicManager.playMusic("resources/main-menu.ogg");

    std::ifstream mapFile("resources/map1.map");

    if (mapFile.is_open()) {
        m_map.loadMap(mapFile);
    } else {
        std::cerr << "Cannot open map file!\n";
    }

    m_player.sprite().setTextureRect(sf::IntRect(64 * 2, 64 * 4, 64, 64));
}

void Game::Scenes::GameScene::onEvent(const sf::Event& event) {
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
        } else if (event.key.code == sf::Keyboard::W) {
            m_player.velocity().y -= 3;
        } else if (event.key.code == sf::Keyboard::A) {
            m_player.velocity().x -= 3;
        } else if (event.key.code == sf::Keyboard::S) {
            m_player.velocity().y += 3;
        } else if (event.key.code == sf::Keyboard::D) {
            m_player.velocity().x += 3;
        }

        m_manager.getWindow().setView(view);
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::W) {
            m_player.velocity().y += 3;
        } else if (event.key.code == sf::Keyboard::A) {
            m_player.velocity().x += 3;
        } else if (event.key.code == sf::Keyboard::S) {
            m_player.velocity().y -= 3;
        } else if (event.key.code == sf::Keyboard::D) {
            m_player.velocity().x -= 3;
        }
    }
}

void Game::Scenes::GameScene::onUpdate(const sf::Time& elapsedTime) {
    ::Engine::Graphics::TextureManager& textureManager = ::Engine::Graphics::TextureManager::getInstance();
    sf::RenderWindow& window = m_manager.getWindow();
    window.clear();

    sf::Font& font = Engine::Graphics::FontManager::getInstance().getFont("arial");
    sf::Sprite sprite;

    for (size_t y = 0; y < m_map.getSize().y; ++y) {
        for (size_t x = 0; x < m_map.getSize().x; ++x) {
            Engine::Map::Cell& cell = m_map.get(x, y);
            sf::Texture& texture = textureManager.getTexture(cell.spriteInfo.tileMapName);
            sprite.setTexture(texture);
            sprite.setPosition(64 * x, 64 * y);
            sprite.setTextureRect(sf::IntRect(cell.spriteInfo.offsetX, cell.spriteInfo.offsetY, 64, 64));
            window.draw(sprite);
        }
    }

    std::vector<Engine::Object::Object>& objects = m_map.getObjects();
    for (size_t i = 0; i < objects.size(); ++i) {
        Engine::Common::Position& pos = objects[i].position();
        sf::Sprite& sp = objects[i].sprite();
        sp.setPosition(64 * pos.x, 64 * pos.y);
        window.draw(sp);
    }

    m_player.onUpdate(elapsedTime);
    m_player.sprite().setPosition(64 * m_player.position().x, 64 * m_player.position().y);
    window.draw(m_player.sprite());

    sf::Text text("FPS: " + std::to_string(int(1.0 / elapsedTime.asSeconds())), font);
    const sf::View& view = window.getView();
    text.setPosition(view.getCenter().x, view.getCenter().y);
    window.draw(text);

    window.display();
}
