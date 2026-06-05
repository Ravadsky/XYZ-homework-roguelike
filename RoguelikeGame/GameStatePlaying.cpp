#include "GameStatePlaying.h"

#include "Application.h"
#include "Game.h"
#include "Text.h"
#include <sstream>

#include "AssetController.h"

namespace RoguelikeGame
{
	GameStatePlayingData::GameStatePlayingData() : GameStateBase()
	{
	}

	GameStatePlayingData::~GameStatePlayingData()
	{
	}

	void GameStatePlayingData::HandleWindowEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				Application::Instance().GetGame().PushState(GameStateType::ExitDialog, false);
			}
		}
	}

	void GameStatePlayingData::Update(float timeDelta)
	{
		GetPlayerInput();

		CheckCollisionsOnScene();

		RemoveMarkedObjects();
	}

	void GameStatePlayingData::Draw(sf::RenderWindow& window)
	{
	}

	void GameStatePlayingData::GetPlayerInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{

		}
	}

	void GameStatePlayingData::RemoveMarkedObjects()
	{
	}

	void GameStatePlayingData::CheckCollisionsOnScene()
	{
	}

}
