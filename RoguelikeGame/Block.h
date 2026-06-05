#pragma once
#include "LevelObject.h"

namespace Arcanoid
{
	class ScoreObserver;

	class Block :
		public LevelObject
	{
	private:
		ScoreObserver* Observer;

	protected:
		int ScoreBaseValue = 1;

	public:
		Block(sf::Vector2f Position);
		virtual ~Block();

		virtual void OnCollision(LevelObject* otherObject) override;

		int GetBaseScore();

		void SetupScoreObserver(ScoreObserver* observer);
	};
}

