#ifndef ENGINE_COMMON_EXCEPTION_H
#define ENGINE_COMMON_EXCEPTION_H

#include <string>
#include <exception>


namespace Engine::Common {
  class Exception: public std::exception
  {
  public:
    explicit Exception(const std::string& message);
    const char* what() const noexcept override;

  private:
    std::string m_message;
  };
}


#endif // ENGINE_COMMON_EXCEPTION_H
