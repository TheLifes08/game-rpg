#include "Exception.h"

Engine::Common::Exception::Exception(const std::string &message, int errorCode) {
    m_message = message;
    m_errorCode = errorCode;
}

const char* Engine::Common::Exception::what() const noexcept {
    return m_message.c_str();
}

int Engine::Common::Exception::errorCode() const noexcept {
    return m_errorCode;
}
