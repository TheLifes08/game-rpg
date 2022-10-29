#ifndef ENGINE_CORE_ACTORCOMPONENT_H
#define ENGINE_CORE_ACTORCOMPONENT_H

#include <engine/core/Object.h>

namespace Engine::Core
{
  class Actor;
  class ActorComponent;

  using ActorComponentPtr = std::shared_ptr<ActorComponent>;
  using ActorWeakPtr = std::weak_ptr<Actor>;

  class ActorComponent: public Object
  {
  public:
    ~ActorComponent() override = default;

  private:
    ActorWeakPtr m_owner;
  };
}

#endif // ENGINE_CORE_ACTORCOMPONENT_H
