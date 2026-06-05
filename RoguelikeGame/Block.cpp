#include "Block.h"
#include "Sprite.h"
#include "ScoreObserver.h"

#include "assert.h"

#include "World.h"
#include "GameStatePlaying.h"
namespace Arcanoid
{
	Block::Block(sf::Vector2f Position) : LevelObject(TextureType::Block, Position)
	{
		ObjectSprite.setColor(GetRandomColor());
	}

	Block::~Block()
	{
		if (Observer)
			Observer->OnBlockDestroyed(this);

		if ((std::rand() % 100) < BONUS_SPAWN_CHANCE)
		{
			GetCurrentWorld()->GetCurrentGamePlaying()->SpawnBonus(ObjectPosition);
		}
	}

	void Block::OnCollision(LevelObject* otherObject)
	{

	}

	int Block::GetBaseScore()
	{
		return ScoreBaseValue;
	}
	void Block::SetupScoreObserver(ScoreObserver* observer)
	{
		Observer = observer;
		Observer->OnBlockAttached(this);
	}
}