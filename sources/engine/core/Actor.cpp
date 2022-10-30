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

  Common::Position Actor::getActorPosition() const
  {
    return m_sceneRootComponent->getPosition();
  }

  void Actor::setActorPosition(const Common::Position& position)
  {
    m_sceneRootComponent->setPosition(position);
  }

  Common::Rotation Actor::getActorRotation() const
  {
    return m_sceneRootComponent->getRotation();
  }

  void Actor::setActorRotation(Common::Rotation rotation)
  {
    m_sceneRootComponent->setRotation(rotation);
  }

  Common::Scale Actor::getActorScale() const
  {
    return m_sceneRootComponent->getScale();
  }

  void Actor::setActorScale(const Common::Scale & scale)
  {
    m_sceneRootComponent->setScale(scale);
  }

  SceneComponentPtr Actor::getSceneRootComponent()
  {
    return m_sceneRootComponent;
  }

  SceneComponentConstPtr Actor::getSceneRootComponent() const
  {
    return m_sceneRootComponent;
  }

  std::vector<ActorComponentPtr> Actor::getActorComponents()
  {
    return m_actorComponents;
  }

  std::vector<ActorComponentConstPtr> Actor::getActorComponents() const
  {
    std::vector<ActorComponentConstPtr> result;
    result.resize(m_actorComponents.size());
    for(size_t i = 0; i < m_actorComponents.size(); ++i)
    {
      result[i] = m_actorComponents[i];
    }
    return result;
  }

  void Actor::addActorComponent(const ActorComponentPtr& component)
  {
    const auto position = std::find(m_actorComponents.begin(), m_actorComponents.end(), component);
    if(position == m_actorComponents.end())
    {
      m_actorComponents.push_back(component);
    }
  }

  void Actor::removeActorComponent(const ActorComponentPtr& component)
  {
    const auto position = std::find(m_actorComponents.begin(), m_actorComponents.end(), component);
    m_actorComponents.erase(position);
  }
}