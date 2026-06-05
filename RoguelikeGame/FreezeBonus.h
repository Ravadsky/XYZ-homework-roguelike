#pragma once
#include "Bonus.h"

namespace Arcanoid
{
	class FreezeBonus :
		public Bonus
	{
	public:
		FreezeBonus(sf::Vector2f position);

		virtual void TriggerEffect() override;
		virtual void TimerCompleted() override;
	};

}

