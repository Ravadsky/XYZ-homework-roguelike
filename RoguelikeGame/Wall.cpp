#include "Wall.h"
#include <World.h>
#include <Object.h>
#include <ResourceSystem.h>
#include <SpriteRendererComponent.h>
#include <RenderSystem.h>
#include <TransformComponent.h>
#include <RigidbodyComponent.h>
#include <SpriteColliderComponent.h>

RoguelikeGame::Wall::Wall()
{
	gameObject = GetWorld()->CreateGameObject();
	auto EnemyRenderer = gameObject->AddComponent<SpriteRendererComponent>();
	EnemyRenderer->SetTexture(*GetResourceSystem()->GetTextureShared("Wall"));
	EnemyRenderer->SetPixelSize(64, 64);

	auto rigidbody = gameObject->AddComponent<RigidbodyComponent>();
	rigidbody->SetKinematic(true);

	gameObject->AddComponent<SpriteColliderComponent>();

}

Object* RoguelikeGame::Wall::GetGameObject()
{
	return gameObject;
}
