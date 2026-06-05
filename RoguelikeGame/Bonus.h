#pragma once
#include "LevelObject.h"
#include "Timer.h"

namespace Arcanoid
{
	class Bonus : public LevelObject, public Timer
	{
	public:
		Bonus(sf::Vector2f Position);

		virtual void Update() override;
		virtual void OnCollision(LevelObject* otherObject) override;

		virtual void TriggerEffect() = 0;

	};

}

