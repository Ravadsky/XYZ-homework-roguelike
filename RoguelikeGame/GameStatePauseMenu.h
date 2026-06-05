#pragma once
#include "GameStateBase.h"

#include "Menu.h"

namespace RoguelikeGame
{
	class GameStatePauseMenuData : public GameStateBase
	{
	private:
		sf::Text titleText;

		Menu menu;
	public:
		GameStatePauseMenuData();
		~GameStatePauseMenuData();

		virtual void HandleWindowEvent(const sf::Event& event) override;
		virtual void Update(float timeDelta) override;
		virtual void Draw(sf::RenderWindow& window) override;

	};
}
