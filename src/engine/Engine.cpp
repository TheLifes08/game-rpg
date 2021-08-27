#include "Engine.h"

Engine::Engine::Engine(): m_loopEnabled(true) {}

int Engine::Engine::execute() {
    int errorCode = initialize();

    while (m_loopEnabled) {
        errorCode = m_manager.start();
        m_loopEnabled = false;
    }

    return errorCode;
}