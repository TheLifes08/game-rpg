#ifndef ENGINE_CORE_ACTOR_H
#define ENGINE_CORE_ACTOR_H

#include <engine/core/Object.h>
#include <engine/core/ActorComponent.h>
#include <engine/core/SceneComponent.h>
#include <vector>

namespace Engine::Core
{
  class Actor;

  using ActorPtr = std::shared_ptr<Actor>;
  using ActorWeakPtr = std::weak_ptr<Actor>;

  class Actor: public Object
  {
  public:
    Actor();
    ~Actor() override = default;

    void onCreate() override;
    void onBeginPlay() override;
    void onTick(double deltaTime) override;
    void onEndPlay() override;

    Math::Vector getActorPosition() const;
    void setActorPosition(const Math::Vector& position);
    double getActorRotation() const;
    void setActorRotation(double rotation);
    Math::Vector getActorScale() const;
    void setActorScale(const Math::Vector& scale);
    Math::Transform getActorTransform() const;
    void setActorTransform(const Math::Transform& transform);

  private:
    SceneComponentPtr m_sceneRootComponent;
    std::vector<ActorComponent> m_actorComponents;
  };
}

#endif // ENGINE_CORE_ACTOR_H
