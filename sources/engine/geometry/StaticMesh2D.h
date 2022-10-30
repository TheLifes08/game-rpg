#ifndef ENGINE_CORE_STATICMESH2D_H
#define ENGINE_CORE_STATICMESH2D_H

#include <engine/common/Types.h>
#include <SFML/Graphics.hpp>
#include <iostream>
namespace Engine::Geometry
{
  struct StaticMesh2D
  {
    sf::VertexArray m_vertexes;
    std::string m_textureName;
    Common::Vector m_pivotPoint;

    void setPivotPoint(const Common::Vector& pivotPoint)
    {
      m_pivotPoint = pivotPoint;
      for (size_t i = 0; i < m_vertexes.getVertexCount(); ++i)
      {
        m_vertexes[i].position = m_vertexes[i].position - pivotPoint;
      }
    }
  };
}

#endif // ENGINE_CORE_STATICMESH2D_H
