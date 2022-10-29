#ifndef ENGINE_CORE_SCENECOMPONENT_H
#define ENGINE_CORE_SCENECOMPONENT_H

#include <engine/core/Object.h>
#include <engine/math/Transform.h>
#include <vector>

namespace Engine::Core
{
  class SceneComponent;

  using SceneComponentPtr = std::shared_ptr<SceneComponent>;

  class SceneComponent: public Object
  {
  public:
    SceneComponent();
    ~SceneComponent() override = default;

    void onCreate() override;
    void onBeginPlay() override;
    void onTick(double deltaTime) override;
    void onEndPlay() override;

    Math::Vector getPosition() const;
    void setPosition(const Math::Vector& position);
    double getRotation() const;
    void setRotation(double rotation);
    Math::Vector getScale() const;
    void setScale(const Math::Vector& scale);
    Math::Transform getTransform() const;
    void setTransform(const Math::Transform& transform);

  private:
    Math::Transform m_transform;
    std::vector<SceneComponentPtr> m_childComponents;
  };
}

#endif // ENGINE_CORE_SCENECOMPONENT_H
