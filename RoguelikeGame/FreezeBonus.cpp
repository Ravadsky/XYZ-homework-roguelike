#include "FreezeBonus.h"
#include "World.h"

Arcanoid::FreezeBonus::FreezeBonus(sf::Vector2f position) : Bonus(position)
{
	TimerTime = 2.f;
	ObjectSprite.setColor(sf::Color::Cyan);

}

void Arcanoid::FreezeBonus::TriggerEffect()
{
	GetCurrentWorld()->PauseEnvironment();
}

void Arcanoid::FreezeBonus::TimerCompleted()
{
	GetCurrentWorld()->UnpauseEnvironment();

	MarkToRemove();
}