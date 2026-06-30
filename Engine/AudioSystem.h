#pragma once
#include "SFML/Audio.hpp"
#include <vector>
#include <memory>

#define GetAudioSystem() AudioSystem::Instance()

class AudioSystem
{
public:
	static AudioSystem* Instance();

	void LoadAndPlayMusic(std::string sourcePath);
	void PlaySound(std::string name);
	void Update();

private:
	AudioSystem();
	~AudioSystem();

	AudioSystem(AudioSystem const&) = delete;
	AudioSystem& operator= (AudioSystem const&) = delete;

	sf::Music music;
	std::vector<std::unique_ptr<sf::Sound>> globalSounds;

	bool HasSimilarSound(std::string name);
};

