#include "Floor.h"
#include <World.h>
#include <Object.h>
#include <ResourceSystem.h>
#include <SpriteRendererComponent.h>
#include <RenderSystem.h>
#include <TransformComponent.h>
#include <RigidbodyComponent.h>
#include <SpriteColliderComponent.h>

RoguelikeGame::Floor::Floor()
{
	gameObject = GetWorld()->CreateGameObject();
	auto EnemyRenderer = gameObject->AddComponent<SpriteRendererComponent>();
	EnemyRenderer->SetTexture(*GetResourceSystem()->GetTextureShared("Floor"));
	EnemyRenderer->SetPixelSize(64, 64);

}

Object* RoguelikeGame::Floor::GetGameObject()
{
	return gameObject;
}
