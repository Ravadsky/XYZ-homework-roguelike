#pragma once
#include "CoreMinimal.h"

namespace RoguelikeGame
{
	class GameStateBase
	{
	protected:
		sf::RectangleShape background;

	public:
		GameStateBase();
		virtual ~GameStateBase() {};

		virtual void HandleWindowEvent(const sf::Event& event) = 0;
		virtual void Update(float timeDelta) = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;
	};
}
