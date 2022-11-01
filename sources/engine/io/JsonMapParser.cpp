#include <engine/io/JsonMapParser.h>
#include <nlohmann/json.hpp>
#include <fstream>

namespace Engine::IO
{
  void JsonMapParser::setMap(const Core::MapWeakPtr& map)
  {
    m_map = map;
  }

  void JsonMapParser::parseMap(const std::string& filepath)
  {
    if (!std::filesystem::exists(filepath))
    {
      throw std::runtime_error{"File '" + filepath + "' does not exist"};
    }

    if (m_map.expired())
    {
      throw std::runtime_error{"Weak pointer to 'Engine::Core::Map' has expired"};
    }

    std::ifstream file(filepath);
    if (!file.is_open())
    {
      throw std::runtime_error{"Error while reading file '" + filepath + "'"};
    }

    const auto json = nlohmann::json::parse(file);
    file.close();

    const auto map = m_map.lock();
    map->clear();

    if (json["compression"] != -1 || json["infinity"] == false || json["type"] != std::string("map") ||
        json["orientation"] != std::string("orthogonal") || json["renderorder"] != std::string("left-up"))
    {
      throw std::runtime_error{"Current map format not supported"};
    }


    // TODO: Finish
  }
}
