#include "Bonus.h"
#include "Sprite.h"
#include "World.h"

Arcanoid::Bonus::Bonus(sf::Vector2f Position) : LevelObject(TextureType::Bonus, Position)
{
}

void Arcanoid::Bonus::Update()
{
	if (IsVisibile())
	{
		Move(sf::Vector2f(0, 1) * INITIAL_SPEED * GetWorldTimeSpeed());

		if (CheckSpriteIntersectionWithBorders(ObjectSprite.getGlobalBounds()))
		{
			MarkToRemove();
		}
	}

}

void Arcanoid::Bonus::OnCollision(LevelObject* otherObject)
{
	GetCurrentWorld()->AttachObjetToTimer(this);

	TriggerEffect();
	Hide();
}

