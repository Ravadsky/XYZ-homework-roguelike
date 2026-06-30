// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include "CoreMinimal.h"
#include "Application.h"

#include <Engine.h>
#include <Windows.h>
#include <iostream>
#include <RenderSystem.h>
#include <ResourceSystem.h>
#include "DeveloperLevel.h"
#include <AudioSystem.h>

using namespace RoguelikeGame;

int main()
{
	if (AllocConsole())
	{
		FILE* fp;
		freopen_s(&fp, "CONOUT$", "w", stdout);
		freopen_s(&fp, "CONOUT$", "w", stderr);
	}
	else
	{
		std::cerr << "cannot capture console" << std::endl;
	}

	sf::RenderWindow window(sf::VideoMode(1280, 720), "XYZ_Roguelike");
	GetRenderSystem()->SetMainWindow(&window);

	GetResourceSystem()->LoadTexture("Player", "Resources/Textures/Player.png", false);
	GetResourceSystem()->LoadTexture("Orc", "Resources/Textures/Orc.png", false);
	GetResourceSystem()->LoadTexture("Wall", "Resources/Textures/Wall.png", false);

	GetResourceSystem()->LoadSoundBuffer("Hit", "Resources/Sounds/Hit.wav");
	GetResourceSystem()->LoadSoundBuffer("Death", "Resources/Sounds/Death.wav");


	GetAudioSystem()->LoadAndPlayMusic("Resources/Music/MainTheme.wav");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	GetEngine()->Run();

	return 0;
}
