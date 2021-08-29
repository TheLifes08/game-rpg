#include "Exception.h"

Engine::Common::Exception::Exception(const std::string &message) {
    m_message = message;
}

const char* Engine::Common::Exception::what() const noexcept {
    return m_message.c_str();
}
