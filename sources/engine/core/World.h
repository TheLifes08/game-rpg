#ifndef ENGINE_CORE_WORLD_H
#define ENGINE_CORE_WORLD_H

#include <engine/core/Object.h>
#include <engine/core/Map.h>
#include <vector>

namespace Engine::Core
{
  class World: public Object
  {
  public:
    World();
    ~World() override = default;

    //void addObject(const ObjectPtr& object);
    //void removeObject(const ObjectPtr& object);

  private:
    std::shared_ptr<Map> m_map;
    std::vector<ObjectPtr> m_objects;
  };
}


#endif // ENGINE_CORE_WORLD_H
