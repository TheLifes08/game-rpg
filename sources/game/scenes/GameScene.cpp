#include "GameScene.h"
#include "../../engine/audio/AudioManager.h"
#include "../../engine/graphics/TextureManager.h"
#include "../../engine/graphics/FontManager.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <engine/core/components/StaticMeshSceneComponent.h>

Game::Scenes::GameScene::GameScene(Engine::Gui::WindowManager& manager)
: Scene(manager), m_player() {
    Engine::Audio::AudioManager& musicManager = ::Engine::Audio::AudioManager::get();

    musicManager.loadSound("content/audio/main-menu.ogg", "main-menu-theme");


        s.openFromFile("content/audio/main-menu.ogg");
        s.setVolume(50);
        s.play();

    std::ifstream mapFile("content/maps/map1.map");

    if (mapFile.is_open()) {
        m_map.loadMap(mapFile);
    } else {
        std::cerr << "Cannot open map file!\n";
    }

  Engine::Graphics::TextureManager& textureManager = Engine::Graphics::TextureManager::getInstance();

    const auto mc = std::make_shared<Engine::Core::StaticMeshSceneComponent>();

    Engine::Geometry::StaticMesh2D mesh;
    mesh.m_textureName = "tiles1";
    mesh.m_vertexes.resize(4);
    mesh.m_vertexes.setPrimitiveType(sf::PrimitiveType::Quads);
    mesh.m_vertexes[0] = sf::Vertex({0, 0}, {64 * 2 + 8, 64 * 4 + 8});
    mesh.m_vertexes[1] = sf::Vertex({48, 0}, {64 * 2 + 8 + 48, 64 * 4 + 8});
    mesh.m_vertexes[2] = sf::Vertex({48, 48}, {64 * 2 + 8 + 48, 64 * 4 + 8 + 48});
    mesh.m_vertexes[3] = sf::Vertex({0, 48}, {64 * 2 + 8, 64 * 4 + 8 + 48});
    mesh.setPivotPoint({24, 24});

    mc->setMesh(mesh);
    m_player.getSceneRootComponent()->addChildSceneComponent(mc);
    //m_player.sprite().setTextureRect(sf::IntRect(64 * 2, 64 * 4, 64, 64));
    //m_player.sprite().setOrigin(32, 32);
  m_player.setActorPosition({128, 128});
}

void Game::Scenes::GameScene::onEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        sf::View view = m_manager.getWindow().getView();
        auto pp = m_player.getActorPosition();

        if (event.key.code == sf::Keyboard::W) {
          pp -= {0, 25};
        } else if (event.key.code == sf::Keyboard::A) {
          pp -= {25, 0};
        } else if (event.key.code == sf::Keyboard::S) {
          pp += {0, 25};
        } else if (event.key.code == sf::Keyboard::D) {
          pp += {25, 0};
        }

        m_player.setActorPosition(pp);

        m_manager.getWindow().setView(view);
    }
}

void Game::Scenes::GameScene::onUpdate(const sf::Time& elapsedTime) {
    Engine::Graphics::TextureManager& textureManager = Engine::Graphics::TextureManager::getInstance();
    Engine::Common::Vector previousPlayerPosition = m_player.getActorPosition();

    // Update all objects
    m_player.onTick(elapsedTime.asSeconds());

    for (auto& object : m_map.getObjects()) {
        object.onTick(elapsedTime.asSeconds());
    }

    // Collision
    auto getTopLeftPoint = [this](int offset) {
        return Engine::Common::Vector (m_player.getActorPosition().x - offset, m_player.getActorPosition().y - offset);
    };
    auto getTopRightPoint = [this](int offset) {
        return Engine::Common::Vector(m_player.getActorPosition().x + offset, m_player.getActorPosition().y - offset);
    };
    auto getBottomLeftPoint = [this](int offset) {
        return Engine::Common::Vector(m_player.getActorPosition().x - offset, m_player.getActorPosition().y + offset);
    };
    auto getBottomRightPoint = [this](int offset) {
        return Engine::Common::Vector(m_player.getActorPosition().x + offset, m_player.getActorPosition().y + offset);
    };

    Engine::Common::Vector topLeftPoint = getTopLeftPoint(20);
    Engine::Common::Vector topRightPoint = getTopRightPoint(20);
    Engine::Common::Vector bottomLeftPoint = getBottomLeftPoint(20);
    Engine::Common::Vector bottomRightPoint = getBottomRightPoint(20);

    bool topLeftCollision = m_map.get(topLeftPoint.x / 64, topLeftPoint.y / 64).solid;
    bool topRightCollision = m_map.get(topRightPoint.x / 64, topRightPoint.y / 64).solid;
    bool bottomLeftCollision = m_map.get(bottomLeftPoint.x / 64, bottomLeftPoint.y / 64).solid;
    bool bottomRightCollision = m_map.get(bottomRightPoint.x / 64, bottomRightPoint.y / 64).solid;

    if (topRightCollision || bottomRightCollision || topLeftCollision || bottomLeftCollision) {
        m_player.setActorPosition(previousPlayerPosition);
    }

    // Clear window
    sf::RenderWindow& window = m_manager.getWindow();
    window.clear();

    // Move view
    sf::View view = window.getView();
    double viewX = m_player.getActorPosition().x;
    double viewY = m_player.getActorPosition().y;


    if (viewX < view.getSize().x / 2) {
       // viewX = view.getSize().x / 2;
    }

    if (viewY < view.getSize().y / 2) {
       // viewY = view.getSize().y / 2;
    }


    view.setCenter(static_cast<float>(round(viewX)), static_cast<float>(round(viewY)));
    m_manager.getWindow().setView(view);

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

        //sf::Sprite& objectSprite = object.sprite();
        //objectSprite.setPosition(static_cast<float>(object.position().x), static_cast<float>(object.position().y));
        //window.draw(objectSprite);
    }

    // Draw player
    for(const auto& component : m_player.getSceneRootComponent()->getChildComponents())
    {
      auto mc = std::dynamic_pointer_cast<Engine::Core::StaticMeshSceneComponent>(component);
      if(mc)
      {
        auto mesh = mc->getMesh();
        const auto rc = m_player.getSceneRootComponent();
        const auto texture = textureManager.getTexture(mesh.m_textureName);
        //sprite.setPosition(rc->getPosition());
        //sprite.setRotation(rc->getRotation());
        //sprite.setScale(rc->getScale());
        sf::RenderStates st;
        st.texture = &texture;
        st.transform = m_player.getSceneRootComponent()->getTransform();
        window.draw(mesh.m_vertexes, st);
      }
    }
    //m_player.sprite().setPosition(m_player.position().x, m_player.position().y);
    //window.draw(m_player.sprite());

    // Draw UI
    sf::Font& uiFont = Engine::Graphics::FontManager::getInstance().getFont("arial");
    sf::Text text("", uiFont, 10);
    Engine::Common::Vector textOffset = {2, 1};

    text.setString("FPS: " + std::to_string(static_cast<int>(1.0 / elapsedTime.asSeconds())));
    text.setPosition(static_cast<float>(view.getCenter().x - view.getSize().x / 2 + textOffset.x),
                     static_cast<float>(view.getCenter().y - view.getSize().y / 2 + textOffset.y));

    window.draw(text);

    // Draw debug lines
    /*auto drawLine = [&window](sf::Vector2f p1, sf::Vector2f p2){
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
    drawLine(sf::Vector2f(bottomLeftPoint.x, bottomLeftPoint.y), sf::Vector2f(topLeftPoint.x, topLeftPoint.y));*/

    // Display window
    window.display();
}
