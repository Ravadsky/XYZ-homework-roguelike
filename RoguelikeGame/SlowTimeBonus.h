#pragma once
#include "Bonus.h"

namespace Arcanoid
{
	class SlowTimeBonus :
		public Bonus
	{
	public:
		SlowTimeBonus(sf::Vector2f position);

		virtual void TriggerEffect() override;
		virtual void TimerCompleted() override;
	};
}


