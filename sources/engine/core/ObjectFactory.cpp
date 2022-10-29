#include <engine/core/ObjectFactory.h>

namespace Engine::Core
{
  ObjectFactory::ObjectFactory():
    m_lastObjectId(0)
  {}

  ObjectFactory& ObjectFactory::get()
  {
    static ObjectFactory instance;
    return instance;
  }
}
