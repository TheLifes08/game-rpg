#ifndef ENGINE_IO_JSONMAPPARSER_H
#define ENGINE_IO_JSONMAPPARSER_H

#include <engine/io/MapParser.h>

namespace Engine::IO
{
  class JsonMapParser: public MapParser
  {
  public:
    void setMap(const Core::MapWeakPtr& map) override;
    void parseMap(const std::string& filepath) override;

  private:
    Core::MapWeakPtr m_map;
  };
}

#endif // ENGINE_IO_JSONMAPPARSER_H
