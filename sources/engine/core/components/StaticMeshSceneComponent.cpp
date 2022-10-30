#include <engine/core/components/StaticMeshSceneComponent.h>

namespace Engine::Core
{
  const Geometry::StaticMesh2D& StaticMeshSceneComponent::getMesh() const
  {
    return m_mesh;
  }

  void StaticMeshSceneComponent::setMesh(const Geometry::StaticMesh2D& mesh)
  {
    m_mesh = mesh;
  }
}
