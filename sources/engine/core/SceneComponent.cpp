#include <engine/core/SceneComponent.h>

namespace Engine::Core
{
  SceneComponent::SceneComponent():
    Object(),
    m_position{0, 0},
    m_rotation{0},
    m_scale{1, 1}
  {
    updateTransformMatrix();
  }

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

  Common::Position SceneComponent::getPosition() const
  {
    return m_position;
  }

  void SceneComponent::setPosition(const Common::Position& position)
  {
    m_position = position;
    updateTransformMatrix();
  }

  Common::Rotation SceneComponent::getRotation() const
  {
    return m_rotation;
  }

  void SceneComponent::setRotation(Common::Rotation rotation)
  {
    m_rotation = rotation;
    updateTransformMatrix();
  }

  Common::Vector SceneComponent::getScale() const
  {
    return m_scale;
  }

  void SceneComponent::setScale(const Common::Vector& scale)
  {
    m_scale = scale;
    updateTransformMatrix();
  }

  Common::Transform SceneComponent::getTransform() const
  {
    return m_transform;
  }

  std::vector<SceneComponentPtr> SceneComponent::getChildComponents()
  {
    return m_childComponents;
  }

  std::vector<SceneComponentConstPtr> SceneComponent::getChildComponents() const
  {
    return std::vector<SceneComponentConstPtr>();
  }

  void SceneComponent::addChildSceneComponent(const SceneComponentPtr& component)
  {
    if(component.get() == this)
    {
      return;
    }

    const auto position = std::find(m_childComponents.begin(), m_childComponents.end(), component);
    if(position == m_childComponents.end())
    {
      m_childComponents.push_back(component);
    }
  }

  void SceneComponent::removeChildSceneComponent(const SceneComponentPtr& component)
  {
    const auto position = std::find(m_childComponents.begin(), m_childComponents.end(), component);
    m_childComponents.erase(position);
  }

  void SceneComponent::updateTransformMatrix()
  {
    m_transform = sf::Transform::Identity;
    m_transform.translate(m_position);
    m_transform.rotate(m_rotation);
    m_transform.scale(m_scale);
  }
}
