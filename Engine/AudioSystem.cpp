#include "pch.h"
#include "AudioSystem.h"
#include "ResourceSystem.h"
#include <iostream>

AudioSystem* AudioSystem::Instance()
{
	static AudioSystem audio;
	return &audio;
}

AudioSystem::AudioSystem()
{
	music.setLoop(true);
}

AudioSystem::~AudioSystem()
{
	globalSounds.clear();

}

bool AudioSystem::HasSimilarSound(std::string name)
{
	auto buffer = GetResourceSystem()->GetSoundBufferShared(name);

	if (buffer == nullptr)
		return false;

	for (auto iterator = globalSounds.begin(); iterator != globalSounds.end(); iterator++)
	{
		if (iterator->get()->getBuffer() == buffer)
			return true;
	}
	return false;
}

void AudioSystem::LoadAndPlayMusic(std::string sourcePath)
{
	music.openFromFile(sourcePath);
	music.setVolume(10.0f);
	music.play();
}

void AudioSystem::PlaySound(std::string name)
{
	if (!HasSimilarSound(name))
	{
		auto buffer = GetResourceSystem()->GetSoundBufferShared(name);
		if (buffer != nullptr)
		{
			auto sound = std::make_unique<sf::Sound>();
			sound->setBuffer(*buffer);
			sound->play();
			sound->setVolume(20.0f);
			sound->setLoop(false);

			globalSounds.push_back(std::move(sound));
		}
		else
		{
			std::cout << "Error: play sound with invalid sound name" << std::endl;
		}
	}
}

void AudioSystem::Update()
{
	auto iterator = globalSounds.begin();

	while (iterator != globalSounds.end())
	{
		if ((*iterator)->getStatus() == sf::Sound::Stopped)
			iterator = globalSounds.erase(iterator);
		else
			++iterator;
	}
}
