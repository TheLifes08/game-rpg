#ifndef ENGINE_COMMON_EXCEPTION_H
#define ENGINE_COMMON_EXCEPTION_H

#include <string>
#include <exception>


namespace Engine {
    namespace Common {
        class Exception : public std::exception {
        public:
            explicit Exception(const std::string& message, int errorCode = 0);
            const char* what() const noexcept override;
            int errorCode() const noexcept;

        private:
            std::string m_message;
            int m_errorCode;
        };
    }
}


#endif // ENGINE_COMMON_EXCEPTION_H
