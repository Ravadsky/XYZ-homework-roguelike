#include "Player.h"

#include <World.h>
#include <Object.h>
#include <SpriteRendererComponent.h>
#include <ResourceSystem.h>
#include <CameraComponent.h>
#include <RenderSystem.h>
#include <InputComponent.h>

RoguelikeGame::Player::Player()
{
	gameObject = World::Instance()->CreateGameObject();

	auto PlayerRenderer = gameObject->AddComponent<SpriteRendererComponent>();
	PlayerRenderer->SetTexture(*ResourceSystem::Instance()->GetTextureShared("ball"));
	PlayerRenderer->SetPixelSize(32, 32);

	auto PlayerCamera = gameObject->AddComponent<CameraComponent>();
	PlayerCamera->SetWindow(&RenderSystem::Instance()->GetMainWindow());
	PlayerCamera->SetBaseResolution(1280, 720);

	auto PlayerInput = gameObject->AddComponent<InputComponent>();
}

Object* RoguelikeGame::Player::GetGameObject()
{
	return gameObject;
}
