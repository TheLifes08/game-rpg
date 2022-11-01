#ifndef ENGINE_CORE_MAP_H
#define ENGINE_CORE_MAP_H

#include <string>
#include <memory>
#include <vector>
#include <engine/common/Types.h>
#include <engine/core/Object.h>
#include <iostream>

// TODO: Fix

namespace Engine::Core
{
  struct SpriteInfo {
    std::string tileMapName;
    size_t offsetX;
    size_t offsetY;

    SpriteInfo(size_t offsetX, size_t offsetY, const std::string& tileMapName):
      offsetX{offsetX},
      offsetY{offsetY},
      tileMapName{tileMapName}
    {}
  };

  struct Cell {
    static const size_t cellSizeX = 64;
    static const size_t cellSizeY = 64;

    SpriteInfo spriteInfo = {0, 0, ""};
    bool solid = false;
  };

  struct MapChunk
  {
    int x;
    int y;
    int width;
    int height;
    std::vector<short> data;
  };

  struct MapLayer
  {
    int id;
    int x, startX;
    int y, startY;
    int width;
    int height;
    bool visible;
    float opacity;
    std::string type;
    std::vector<MapChunk> chunks;
  };

  using MapLayerPtr = std::shared_ptr<MapLayer>;

  class Map {
  public:
    Map();

    Cell& get(size_t x, size_t y);
    Cell& get(double x, double y);
    Common::Size getSize() const;
    Common::Size getTilesSize() const;
    size_t getLayerCount() const;
    MapLayerPtr getLayer(size_t index);
    void addLayer(const MapLayerPtr& layer);
    std::vector<Core::ObjectPtr> getObjects();
    void clearObjects();
    void clear();


  private:
    Common::Size m_size;
    Common::Size m_tilesSize;
    std::vector<MapLayer> m_layers;
    std::vector<Core::ObjectPtr> m_objects;
  };

  using MapPtr = std::shared_ptr<Map>;
  using MapWeakPtr = std::weak_ptr<Map>;
}

#endif // ENGINE_CORE_MAP_H
