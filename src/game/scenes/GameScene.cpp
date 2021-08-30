#include "GameScene.h"
#include "../../engine/audio/MusicManager.h"
#include "../../engine/graphics/TextureManager.h"
#include "../../engine/graphics/FontManager.h"
#include <iostream>
#include <fstream>
#include <cmath>

Game::Scenes::GameScene::GameScene(Engine::Gui::WindowManager& manager)
: Scene(manager), m_player("tiles1", {1, 1}) {
    Engine::Audio::MusicManager& musicManager = ::Engine::Audio::MusicManager::getInstance();

    musicManager.playMusic("resources/main-menu.ogg");

    std::ifstream mapFile("resources/map1.map");

    if (mapFile.is_open()) {
        m_map.loadMap(mapFile);
    } else {
        std::cerr << "Cannot open map file!\n";
    }

    m_player.sprite().setTextureRect(sf::IntRect(64 * 2, 64 * 4, 64, 64));
    m_player.sprite().setOrigin(32, 32);
    m_player.position().x = 128;
    m_player.position().y = 128;
}

void Game::Scenes::GameScene::onEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        sf::View view = m_manager.getWindow().getView();

        if (event.key.code == sf::Keyboard::W) {
            m_player.velocity().y -= 200;
        } else if (event.key.code == sf::Keyboard::A) {
            m_player.velocity().x -= 200;
        } else if (event.key.code == sf::Keyboard::S) {
            m_player.velocity().y += 200;
        } else if (event.key.code == sf::Keyboard::D) {
            m_player.velocity().x += 200;
        }

        m_manager.getWindow().setView(view);
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::W) {
            m_player.velocity().y += 200;
        } else if (event.key.code == sf::Keyboard::A) {
            m_player.velocity().x += 200;
        } else if (event.key.code == sf::Keyboard::S) {
            m_player.velocity().y -= 200;
        } else if (event.key.code == sf::Keyboard::D) {
            m_player.velocity().x -= 200;
        }
    }
}

void Game::Scenes::GameScene::onUpdate(const sf::Time& elapsedTime) {
    Engine::Graphics::TextureManager& textureManager = Engine::Graphics::TextureManager::getInstance();
    Engine::Common::Position previousPlayerPosition = m_player.position();

    // Update all objects
    m_player.onUpdate(elapsedTime);

    for (auto& object : m_map.getObjects()) {
        object.onUpdate(elapsedTime);
    }

    // Collision
    auto getTopLeftPoint = [this](int offset) {
        return Engine::Common::Position(m_player.position().x - offset, m_player.position().y - offset);
    };
    auto getTopRightPoint = [this](int offset) {
        return Engine::Common::Position(m_player.position().x + offset, m_player.position().y - offset);
    };
    auto getBottomLeftPoint = [this](int offset) {
        return Engine::Common::Position(m_player.position().x - offset, m_player.position().y + offset);
    };
    auto getBottomRightPoint = [this](int offset) {
        return Engine::Common::Position(m_player.position().x + offset, m_player.position().y + offset);
    };

    Engine::Common::Position topLeftPoint = getTopLeftPoint(20);
    Engine::Common::Position topRightPoint = getTopRightPoint(20);
    Engine::Common::Position bottomLeftPoint = getBottomLeftPoint(20);
    Engine::Common::Position bottomRightPoint = getBottomRightPoint(20);

    bool topLeftCollision = m_map.get(topLeftPoint.x / 64, topLeftPoint.y / 64).solid;
    bool topRightCollision = m_map.get(topRightPoint.x / 64, topRightPoint.y / 64).solid;
    bool bottomLeftCollision = m_map.get(bottomLeftPoint.x / 64, bottomLeftPoint.y / 64).solid;
    bool bottomRightCollision = m_map.get(bottomRightPoint.x / 64, bottomRightPoint.y / 64).solid;

    if (topRightCollision || bottomRightCollision || topLeftCollision || bottomLeftCollision) {
        m_player.position() = previousPlayerPosition;
    }

    // Clear window
    sf::RenderWindow& window = m_manager.getWindow();
    window.clear();

    // Draw tiles
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

    // Draw objects
    for (auto& object : m_map.getObjects()) {
        sf::Sprite& objectSprite = object.sprite();
        objectSprite.setPosition(static_cast<float>(object.position().x), static_cast<float>(object.position().y));
        window.draw(objectSprite);
    }

    // Draw player
    m_player.sprite().setPosition(m_player.position().x, m_player.position().y);
    window.draw(m_player.sprite());

    // Draw UI
    sf::Font& uiFont = Engine::Graphics::FontManager::getInstance().getFont("arial");
    sf::View view = window.getView();
    sf::Text text("", uiFont, 10);
    Engine::Common::Position textOffset = {2, 1};

    text.setString("FPS: " + std::to_string(static_cast<int>(1.0 / elapsedTime.asSeconds())));
    text.setPosition(static_cast<float>(view.getCenter().x - view.getSize().x / 2 + textOffset.x),
                     static_cast<float>(view.getCenter().y - view.getSize().y / 2 + textOffset.y));

    window.draw(text);

    // Draw debug lines
    auto drawLine = [&window](sf::Vector2f p1, sf::Vector2f p2){
        sf::Vertex line[] = {
                sf::Vertex(p1),
                sf::Vertex(p2)
        };
        window.draw(line, 2, sf::Lines);
    };

    for (size_t y = 0; y < m_map.getSize().y; ++y) {
        for (size_t x = 0; x < m_map.getSize().x; ++x) {
            if (m_map.get(x, y).solid) {
                drawLine(sf::Vector2f(64 * x, 64 * y), sf::Vector2f(64 * x + 64, 64 * y));
                drawLine(sf::Vector2f(64 * x + 64, 64 * y), sf::Vector2f(64 * x + 64, 64 * y + 64));
                drawLine(sf::Vector2f(64 * x + 64, 64 * y + 64), sf::Vector2f(64 * x, 64 * y + 64));
                drawLine(sf::Vector2f(64 * x, 64 * y + 64), sf::Vector2f(64 * x, 64 * y));
            }
        }
    }

    topLeftPoint = getTopLeftPoint(20);
    topRightPoint = getTopRightPoint(20);
    bottomLeftPoint = getBottomLeftPoint(20);
    bottomRightPoint = getBottomRightPoint(20);

    drawLine(sf::Vector2f(topLeftPoint.x, topLeftPoint.y), sf::Vector2f(topRightPoint.x, topRightPoint.y));
    drawLine(sf::Vector2f(topRightPoint.x, topRightPoint.y), sf::Vector2f(bottomRightPoint.x, bottomRightPoint.y));
    drawLine(sf::Vector2f(bottomRightPoint.x, bottomRightPoint.y), sf::Vector2f(bottomLeftPoint.x, bottomLeftPoint.y));
    drawLine(sf::Vector2f(bottomLeftPoint.x, bottomLeftPoint.y), sf::Vector2f(topLeftPoint.x, topLeftPoint.y));

    // Move view
    double viewX = m_player.position().x;
    double viewY = m_player.position().y;

    /*
    if (viewX < view.getSize().x / 2) {
        viewX = view.getSize().x / 2;
    }

    if (viewY < view.getSize().y / 2) {
        viewY = view.getSize().y / 2;
    }*/

    view = window.getView();
    view.setCenter(static_cast<float>(viewX), static_cast<float>(viewY));
    m_manager.getWindow().setView(view);

    // Display window
    window.display();
}
