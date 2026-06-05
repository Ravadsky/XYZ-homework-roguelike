#pragma once
#include "Bonus.h"

namespace Arcanoid
{
    class GrowPlatformBonus :
        public Bonus
    {
    public:
        GrowPlatformBonus(sf::Vector2f position);

        virtual void TriggerEffect() override;
        virtual void TimerCompleted() override;
    };
}


