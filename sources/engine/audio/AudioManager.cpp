#include <engine/audio/AudioManager.h>
#include <filesystem>
#include <iostream>
namespace Engine::Audio
{
  AudioManager& AudioManager::get()
  {
    static AudioManager musicManager;
    return musicManager;
  }

  bool AudioManager::loadSound(const std::string& path, const std::string& name)
  {
    if (path.empty() || !std::filesystem::exists(path) || m_sounds.contains(name))
    {
      return false;
    }

    sf::SoundBuffer buffer;

    if (!buffer.loadFromFile(path))
    {
      return false;
    }

    m_sounds[name] = buffer;
    std::cerr << "hi";

    return false;
  }

  const sf::SoundBuffer& AudioManager::getSound(const std::string& name)
  {
    if (!m_sounds.contains(name))
    {
      throw std::runtime_error{"No sound named '" + name + "'"};
    }
    return m_sounds[name];
  }
}
