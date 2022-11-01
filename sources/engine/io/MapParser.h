#ifndef ENGINE_IO_MAPPARSER_H
#define ENGINE_IO_MAPPARSER_H

#include <engine/core/Map.h>

namespace Engine::IO
{
  class MapParser
  {
  public:
    virtual void setMap(const Core::MapWeakPtr& map) = 0;
    virtual void parseMap(const std::string& filepath) = 0;
    virtual ~MapParser() = default;
  };
}

#endif //ENGINE_IO_MAPPARSER_H
