#include "DeveloperLevel.h"
#include <World.h>

void RoguelikeGame::DeveloperLevel::Start()
{
	player = std::make_shared<Player>();
}

void RoguelikeGame::DeveloperLevel::Restart()
{
	Stop();
	Start();
}

void RoguelikeGame::DeveloperLevel::Stop()
{
	World::Instance()->Clear();
}
