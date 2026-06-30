#include "DeveloperLevel.h"
#include <World.h>
#include <Object.h>
#include <PursuitComponent.h>

void RoguelikeGame::DeveloperLevel::Start()
{
	player = std::make_shared<Player>();
	orc = std::make_shared<Enemy>();

	auto Pursuiter = orc->GetGameObject()->GetComponent<PursuitComponent>();
	Pursuiter->SetPursuitTarget(player->GetGameObject());

}

void RoguelikeGame::DeveloperLevel::Restart()
{
	Stop();
	Start();
}

void RoguelikeGame::DeveloperLevel::Stop()
{
	GetWorld()->Clear();
}
