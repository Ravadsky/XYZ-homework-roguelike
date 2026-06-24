#include "pch.h"
#include "Engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "RenderSystem.h"
#include "World.h"

Engine::Engine()
{
	unsigned int seed = (unsigned int)time(nullptr);
	srand(seed);
}

Engine* Engine::Instance()
{
	static Engine engine;
	return &engine;
}

void Engine::Run()
{
	sf::Clock gameClock;
	sf::Event event;

	while (RenderSystem::Instance()->GetMainWindow().isOpen())
	{
		sf::Time dt = gameClock.restart();
		float deltaTime = dt.asSeconds();

		while (RenderSystem::Instance()->GetMainWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				RenderSystem::Instance()->GetMainWindow().close();
			}
		}
		if (!RenderSystem::Instance()->GetMainWindow().isOpen())
		{
			break;
		}

		RenderSystem::Instance()->GetMainWindow().clear();
		World::Instance()->Update(deltaTime);
		World::Instance()->Render();
		World::Instance()->LateUpdate();
		RenderSystem::Instance()->GetMainWindow().display();
	}

}
