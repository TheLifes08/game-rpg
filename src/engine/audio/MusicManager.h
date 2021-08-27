#ifndef ENGINE_AUDIO_MUSIC_MANAGER_H
#define ENGINE_AUDIO_MUSIC_MANAGER_H

#include <SFML/Audio.hpp>
#include <string>


namespace Engine {
    namespace Audio {
        class MusicManager {
        public:
            MusicManager(const MusicManager&) = delete;
            MusicManager(MusicManager&&) = delete;
            MusicManager& operator=(const MusicManager&) = delete;
            MusicManager& operator=(MusicManager&&) = delete;

            static MusicManager& getInstance();
            bool playMusic(const std::string& path);

        private:
            MusicManager() = default;

            sf::Music m_music;
        };
    }
}


#endif // ENGINE_AUDIO_MUSIC_MANAGER_H
