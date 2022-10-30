#ifndef ENGINE_CORE_STATICMESHSCENECOMPONENT_H
#define ENGINE_CORE_STATICMESHSCENECOMPONENT_H

#include <engine/core/SceneComponent.h>
#include <engine/geometry/StaticMesh2D.h>

namespace Engine::Core
{
  class StaticMeshSceneComponent: public SceneComponent
  {
  public:
    ~StaticMeshSceneComponent() override = default;

    const Geometry::StaticMesh2D& getMesh() const;
    void setMesh(const Geometry::StaticMesh2D& mesh);

  private:
    Geometry::StaticMesh2D m_mesh;
  };
}

#endif // ENGINE_CORE_STATICMESHSCENECOMPONENT_H
