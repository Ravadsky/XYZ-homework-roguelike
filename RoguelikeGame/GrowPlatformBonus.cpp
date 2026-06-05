#include "GrowPlatformBonus.h"
#include "World.h"
#include "GameStatePlaying.h"
#include "Platform.h"

Arcanoid::GrowPlatformBonus::GrowPlatformBonus(sf::Vector2f position) : Bonus(position)
{
	TimerTime = 5.f;
	ObjectSprite.setColor(sf::Color::Green);
}

void Arcanoid::GrowPlatformBonus::TriggerEffect()
{
	GetCurrentWorld()->GetCurrentGamePlaying()->getPlatform()->GrowUp();
}

void Arcanoid::GrowPlatformBonus::TimerCompleted()
{
	GetCurrentWorld()->GetCurrentGamePlaying()->getPlatform()->GrowDown();

	MarkToRemove();
}