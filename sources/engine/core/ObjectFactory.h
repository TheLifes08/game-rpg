#ifndef ENGINE_CORE_OBJECTFACTORY_H
#define ENGINE_CORE_OBJECTFACTORY_H

#include <engine/core/Object.h>
#include <engine/core/Actor.h>
#include <engine/core/ActorComponent.h>
#include <engine/core/SceneComponent.h>

namespace Engine::Core
{
  template<typename T>
  concept IsObject = std::is_base_of_v<Object, T>;

  template<typename T>
  concept IsActor = std::is_base_of_v<Actor, T>;

  template<typename T>
  concept IsActorComponent = std::is_base_of_v<SceneComponent, T>;

  template<typename T>
  concept IsSceneComponent = std::is_base_of_v<SceneComponent, T>;

  class ObjectFactory
  {
  public:
    static ObjectFactory& get();

    template<IsObject T>
    inline ObjectPtr createObject()
    {
      const auto object = std::make_shared<T>();
      object->setObjectId(++m_lastObjectId);
      object->setObjectName(std::to_string(m_lastObjectId));
      return object;
    }

    template<IsObject T>
    inline ActorPtr createActor()
    {
      const auto object = std::make_shared<T>();
      object->setObjectId(++m_lastObjectId);
      object->setObjectName(std::to_string(m_lastObjectId));
      return object;
    }

    template<IsActorComponent T>
    inline ActorComponentPtr createActorComponent()
    {
      const auto object = std::make_shared<T>();
      object->setObjectId(++m_lastObjectId);
      object->setObjectName(std::to_string(m_lastObjectId));
      return object;
    }

    template<IsSceneComponent T>
    inline SceneComponentPtr createSceneComponent()
    {
      const auto object = std::make_shared<T>();
      object->setObjectId(++m_lastObjectId);
      object->setObjectName(std::to_string(m_lastObjectId));
      return object;
    }

  private:
    ObjectFactory();

  private:
    uint64_t m_lastObjectId;
  };
}

#endif // ENGINE_CORE_OBJECTFACTORY_H
