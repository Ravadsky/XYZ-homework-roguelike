#pragma once
#include "GameStateBase.h"
#include <vector>
#include <memory>

namespace RoguelikeGame
{

	class GameStatePlayingData : public GameStateBase
	{
	private:

	public:
		GameStatePlayingData();
		~GameStatePlayingData();

		virtual void HandleWindowEvent(const sf::Event& event) override;
		virtual void Update(float timeDelta) override;
		virtual void Draw(sf::RenderWindow& window) override;

		void GetPlayerInput();

		void InitializeScene();

		void RemoveMarkedObjects();
		void CheckCollisionsOnScene();

	};
}
