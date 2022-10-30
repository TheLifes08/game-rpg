#ifndef ENGINE_CORE_SCENECOMPONENT_H
#define ENGINE_CORE_SCENECOMPONENT_H

#include <engine/common/Types.h>
#include <engine/core/Object.h>
#include <vector>

namespace Engine::Core
{
  class SceneComponent;

  using SceneComponentPtr = std::shared_ptr<SceneComponent>;
  using SceneComponentConstPtr = std::shared_ptr<const SceneComponent>;

  class SceneComponent: public Object
  {
  public:
    SceneComponent();
    ~SceneComponent() override = default;

    void onCreate() override;
    void onBeginPlay() override;
    void onTick(double deltaTime) override;
    void onEndPlay() override;

    Common::Position getPosition() const;
    void setPosition(const Common::Position& position);

    Common::Rotation getRotation() const;
    void setRotation(Common::Rotation rotation);

    Common::Scale getScale() const;
    void setScale(const Common::Scale& scale);

    Common::Transform getTransform() const;

    std::vector<SceneComponentPtr> getChildComponents();
    std::vector<SceneComponentConstPtr> getChildComponents() const;

    void addChildSceneComponent(const SceneComponentPtr& component);
    void removeChildSceneComponent(const SceneComponentPtr& component);

  private:
    void updateTransformMatrix();

  private:
    Common::Position m_position;
    Common::Rotation m_rotation;
    Common::Scale m_scale;
    Common::Transform m_transform;
    std::vector<SceneComponentPtr> m_childComponents;
  };
}

#endif // ENGINE_CORE_SCENECOMPONENT_H
