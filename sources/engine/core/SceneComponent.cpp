#include <engine/core/SceneComponent.h>

namespace Engine::Core
{
  SceneComponent::SceneComponent():
    Object(),
    m_transform{{0, 0}, 0, {1, 1}}
  {}

  void SceneComponent::onCreate()
  {
    for (const auto& component : m_childComponents)
    {
      component->onCreate();
    }
  }

  void SceneComponent::onBeginPlay()
  {
    for (const auto& component : m_childComponents)
    {
      component->onBeginPlay();
    }
  }

  void SceneComponent::onTick(double deltaTime)
  {
    for (const auto& component : m_childComponents)
    {
      component->onTick(deltaTime);
    }
  }

  void SceneComponent::onEndPlay()
  {
    for (const auto& component : m_childComponents)
    {
      component->onEndPlay();
    }
  }

  Math::Vector SceneComponent::getPosition() const
  {
    return m_transform.position;
  }

  void SceneComponent::setPosition(const Math::Vector& position)
  {
    m_transform.position = position;
  }

  double SceneComponent::getRotation() const
  {
    return m_transform.rotation;
  }

  void SceneComponent::setRotation(double rotation)
  {
    m_transform.rotation = rotation;
  }

  Math::Vector SceneComponent::getScale() const
  {
    return m_transform.scale;
  }

  void SceneComponent::setScale(const Math::Vector& scale)
  {
    m_transform.scale = scale;
  }

  Math::Transform SceneComponent::getTransform() const
  {
    return m_transform;
  }

  void SceneComponent::setTransform(const Math::Transform& transform)
  {
    m_transform = transform;
  }
}
