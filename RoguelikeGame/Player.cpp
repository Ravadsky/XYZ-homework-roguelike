#include "Player.h"

#include <World.h>
#include <Object.h>
#include <SpriteRendererComponent.h>
#include <ResourceSystem.h>
#include <CameraComponent.h>
#include <RenderSystem.h>
#include <InputComponent.h>
#include <TransformComponent.h>
#include <RigidbodyComponent.h>
#include <SpriteColliderComponent.h>
#include <CharacterMovementComponent.h>

RoguelikeGame::Player::Player()
{
	gameObject = GetWorld()->CreateGameObject();
	auto PlayerRenderer = gameObject->AddComponent<SpriteRendererComponent>();
	PlayerRenderer->SetTexture(*GetResourceSystem()->GetTextureShared("Player"));
	PlayerRenderer->SetPixelSize(64, 64);

	auto PlayerCamera = gameObject->AddComponent<CameraComponent>();
	PlayerCamera->SetWindow(&GetRenderSystem()->GetMainWindow());
	PlayerCamera->SetBaseResolution(1280, 720);

	auto PlayerTransform = gameObject->GetComponent<TransformComponent>();

	auto PlayerInput = gameObject->AddComponent<InputComponent>();

	auto body = gameObject->AddComponent<RigidbodyComponent>();

	auto collider = gameObject->AddComponent<SpriteColliderComponent>();

	auto movement = gameObject->AddComponent<CharacterMovementComponent>();
	movement->SetMovementSpeed(40.0f);
}

Object* RoguelikeGame::Player::GetGameObject()
{
	return gameObject;
}
