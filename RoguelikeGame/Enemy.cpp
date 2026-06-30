#include "Enemy.h"
#include <World.h>
#include <Object.h>
#include <ResourceSystem.h>
#include <SpriteRendererComponent.h>
#include <RenderSystem.h>
#include <TransformComponent.h>
#include <PursuitComponent.h>
#include <RigidbodyComponent.h>
#include <SpriteColliderComponent.h>
#include <CharacterMovementComponent.h>

RoguelikeGame::Enemy::Enemy()
{
	gameObject = GetWorld()->CreateGameObject();
	auto EnemyRenderer = gameObject->AddComponent<SpriteRendererComponent>();
	EnemyRenderer->SetTexture(*GetResourceSystem()->GetTextureShared("Orc"));
	EnemyRenderer->SetPixelSize(64, 64);

	gameObject->AddComponent<PursuitComponent>();

	auto EnemyTransform = gameObject->GetComponent<TransformComponent>();
	EnemyTransform->SetWorldPosition(0.f, 126.f);

	gameObject->AddComponent<RigidbodyComponent>();

	gameObject->AddComponent<SpriteColliderComponent>();

	gameObject->AddComponent<CharacterMovementComponent>();

}

Object* RoguelikeGame::Enemy::GetGameObject()
{
    return gameObject;
}
