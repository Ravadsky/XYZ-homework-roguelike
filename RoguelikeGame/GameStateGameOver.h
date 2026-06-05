#pragma once
#include "GameStateBase.h"

namespace RoguelikeGame
{
	class GameStateGameOverData : public GameStateBase
	{
	private:
		float timeSinceGameOver = 0.f;

		// UI data
		sf::Text gameOverText;
		sf::Text hintText;

	public:
		GameStateGameOverData();
		~GameStateGameOverData();

		virtual void HandleWindowEvent(const sf::Event& event) override;
		virtual void Update(float timeDelta) override;
		virtual void Draw(sf::RenderWindow& window) override;
	};

}
