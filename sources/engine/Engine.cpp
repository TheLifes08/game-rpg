#include "Engine.h"

int Engine::Engine::execute() {
    int errorCode = initialize();

    if (errorCode == 0) {
        m_manager.start();
    }

    return 0;
}

int Engine::Engine::initialize() {
    return 0;
}
