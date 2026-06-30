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

	while (GetRenderSystem()->GetMainWindow().isOpen())
	{
		sf::Time dt = gameClock.restart();
		float deltaTime = dt.asSeconds();

		while (GetRenderSystem()->GetMainWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				GetRenderSystem()->GetMainWindow().close();
			}
		}
		if (!GetRenderSystem()->GetMainWindow().isOpen())
		{
			break;
		}

		GetRenderSystem()->GetMainWindow().clear();
		GetWorld()->Update(deltaTime);
		GetWorld()->FixedUpdate(deltaTime);
		GetWorld()->Render();
		GetWorld()->LateUpdate();
		GetRenderSystem()->GetMainWindow().display();
	}

}
