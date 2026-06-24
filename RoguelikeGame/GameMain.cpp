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
	RenderSystem::Instance()->SetMainWindow(&window);
	ResourceSystem::Instance()->LoadTexture("ball", "Resources/Textures/ball.png");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	Engine::Instance()->Run();

	return 0;
}
