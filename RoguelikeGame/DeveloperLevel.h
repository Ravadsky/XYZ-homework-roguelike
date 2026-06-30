#pragma once
#include <Scene.h>
#include <memory>
#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "Wall.h"
#include "Floor.h"

namespace RoguelikeGame
{
    class DeveloperLevel :
        public Scene
    {
    public:
        virtual void Start() override;
        virtual void Restart() override;
        virtual void Stop() override;

    private:
        std::shared_ptr<Player> player;
        std::shared_ptr<Enemy> orc;
        std::vector<std::shared_ptr<Wall>> walls;
        std::vector<std::shared_ptr<Floor>> floors;
    };

}

