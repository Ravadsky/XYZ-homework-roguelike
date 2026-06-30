#include "DeveloperLevel.h"
#include <World.h>
#include <Object.h>
#include <PursuitComponent.h>
#include <TransformComponent.h>

void RoguelikeGame::DeveloperLevel::Start()
{
	for (int i = -10; i <= 10; i++)
	{
		for (int j = -10; j <= 10; j++)
		{
			Vector2Df position(i * 64.0f, j * 64.0f);
			floors.emplace_back(std::make_shared<Floor>());

			auto floorTransform = floors.back()->GetGameObject()->GetComponent<TransformComponent>();
			floorTransform->SetWorldPosition(position);

		}
	}


	player = std::make_shared<Player>();
	orc = std::make_shared<Enemy>();

	Vector2Df position(0.0f, 128.0f);
	for (int i = 0; i < 10; i++)
	{
		position = position + Vector2Df(64.0f, 0.0f);
		walls.emplace_back(std::make_shared<Wall>());

		auto wallTransform = walls.back()->GetGameObject()->GetComponent<TransformComponent>();
		wallTransform->SetWorldPosition(position);

		walls.emplace_back(std::make_shared<Wall>());

		wallTransform = walls.back()->GetGameObject()->GetComponent<TransformComponent>();
		wallTransform->SetWorldPosition(position - Vector2Df(0.0f, 256.0f));
	}

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
