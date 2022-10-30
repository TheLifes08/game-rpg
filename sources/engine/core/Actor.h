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

  class Actor: public Object
  {
  public:
    Actor();
    ~Actor() override = default;

    void onCreate() override;
    void onBeginPlay() override;
    void onTick(double deltaTime) override;
    void onEndPlay() override;

    Common::Position getActorPosition() const;
    void setActorPosition(const Common::Position& position);

    Common::Rotation getActorRotation() const;
    void setActorRotation(Common::Rotation rotation);

    Common::Scale getActorScale() const;
    void setActorScale(const Common::Scale& scale);

    SceneComponentPtr getSceneRootComponent();
    SceneComponentConstPtr getSceneRootComponent() const;

    std::vector<ActorComponentPtr> getActorComponents();
    std::vector<ActorComponentConstPtr> getActorComponents() const;

    void addActorComponent(const ActorComponentPtr& component);
    void removeActorComponent(const ActorComponentPtr& component);

  private:
    SceneComponentPtr m_sceneRootComponent;
    std::vector<ActorComponentPtr> m_actorComponents;
  };
}

#endif // ENGINE_CORE_ACTOR_H
