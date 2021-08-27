#include "MusicManager.h"

Engine::Audio::MusicManager& Engine::Audio::MusicManager::getInstance() {
    static MusicManager musicManager;
    return musicManager;
}

bool Engine::Audio::MusicManager::playMusic(const std::string &path) {
    m_music.stop();

    if (path.empty() || !m_music.openFromFile(path)) {
        return false;
    }

    m_music.setLoop(true);
    m_music.play();
}
