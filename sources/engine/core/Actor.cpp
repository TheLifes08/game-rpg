#include <engine/core/Actor.h>
#include <engine/core/ObjectFactory.h>

namespace Engine::Core
{
  Actor::Actor():
    Object(),
    m_sceneRootComponent{ObjectFactory::get().createSceneComponent<SceneComponent>()}
  {}

  void Actor::onCreate()
  {
  }

  void Actor::onBeginPlay()
  {
  }

  void Actor::onTick(double deltaTime)
  {
  }

  void Actor::onEndPlay()
  {
  }

  Math::Vector Actor::getActorPosition() const
  {
    return m_sceneRootComponent->getPosition();
  }

  void Actor::setActorPosition(const Engine::Math::Vector& position)
  {
    m_sceneRootComponent->setPosition(position);
  }

  double Actor::getActorRotation() const
  {
    return m_sceneRootComponent->getRotation();
  }

  void Actor::setActorRotation(double rotation)
  {
    m_sceneRootComponent->setRotation(rotation);
  }

  Math::Vector Actor::getActorScale() const
  {
    return m_sceneRootComponent->getScale();
  }

  void Actor::setActorScale(const Engine::Math::Vector& scale)
  {
    m_sceneRootComponent->setScale(scale);
  }

  Math::Transform Actor::getActorTransform() const
  {
    return m_sceneRootComponent->getTransform();
  }

  void Actor::setActorTransform(const Engine::Math::Transform& transform)
  {
    m_sceneRootComponent->setTransform(transform);
  }
}