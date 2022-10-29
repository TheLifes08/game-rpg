#ifndef ENGINE_CORE_OBJECT_H
#define ENGINE_CORE_OBJECT_H

#include <concepts>
#include <memory>
#include <string>

namespace Engine::Core
{
  class Object;

  using ObjectPtr = std::shared_ptr<Object>;
  using ObjectWeakPtr = std::weak_ptr<Object>;

  class Object
  {
  public:
    Object();
    virtual ~Object() = default;

    void setObjectId(uint64_t id);
    uint64_t getObjectId() const;

    void setObjectName(const std::string& name);
    std::string getObjectName() const;

    virtual void onCreate() = 0;
    virtual void onBeginPlay() = 0;
    virtual void onTick(double deltaTime) = 0;
    virtual void onEndPlay() = 0;

  private:
    uint64_t m_id;
    std::string m_name;
  };
}

#endif // ENGINE_CORE_OBJECT_H
