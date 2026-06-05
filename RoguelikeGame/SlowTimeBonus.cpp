#include "SlowTimeBonus.h"
#include "World.h"

Arcanoid::SlowTimeBonus::SlowTimeBonus(sf::Vector2f position) : Bonus(position)
{
	TimerTime = 5.f;
	ObjectSprite.setColor(sf::Color::Red);
}

void Arcanoid::SlowTimeBonus::TriggerEffect()
{
	GetCurrentWorld()->ChangeTimeSpeed(0.5f);
}

void Arcanoid::SlowTimeBonus::TimerCompleted()
{
	GetCurrentWorld()->ChangeTimeSpeed(1.f);

	MarkToRemove();
}