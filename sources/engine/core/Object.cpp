#include <engine/core/Object.h>

namespace Engine::Core
{
  Object::Object():
    m_id{0}, m_name{""}
  {}

  void Object::setObjectId(uint64_t id)
  {
    m_id = id;
  }

  uint64_t Object::getObjectId() const
  {
    return m_id;
  }

  void Object::setObjectName(const std::string& name)
  {
    m_name = name;
  }

  std::string Object::getObjectName() const
  {
    return m_name;
  }
}