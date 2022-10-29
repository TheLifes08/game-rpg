#ifndef ENGINE_AUDIO_MUSIC_MANAGER_H
#define ENGINE_AUDIO_MUSIC_MANAGER_H

#include <SFML/Audio.hpp>
#include <map>
#include <string>


namespace Engine::Audio {
  class AudioManager
  {
  public:
    AudioManager(const AudioManager&) = delete;
    AudioManager(AudioManager&&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;
    AudioManager& operator=(AudioManager&&) = delete;

    static AudioManager& get();

    bool loadSound(const std::string& path, const std::string& name);
    const sf::SoundBuffer& getSound(const std::string& name);

  private:
    AudioManager() = default;

  private:
    std::map<std::string, sf::SoundBuffer> m_sounds;
  };
}


#endif // ENGINE_AUDIO_MUSIC_MANAGER_H
