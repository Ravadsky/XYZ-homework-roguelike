#include "GameStateBase.h"

RoguelikeGame::GameStateBase::GameStateBase()
{
	sf::Color backgroundColor = sf::Color::Black;
	backgroundColor.a = 200; // a means Alfa, opacity
	background.setFillColor(backgroundColor);
}
