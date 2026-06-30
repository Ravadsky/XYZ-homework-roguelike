#include "pch.h"
#include "World.h"

#include "Object.h"
#include "PhysicsSystem.h"
#include "TransformComponent.h"
#include "AudioSystem.h"

World* World::Instance()
{
	static World world;
	return &world;
}

void World::Update(float deltaTime)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update(deltaTime);
	}
}

void World::Render()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Render();
	}
}

void World::FixedUpdate(float deltaTime)
{
	fixedCounter += deltaTime;
	if (fixedCounter > GetPhysicsSystem()->GetFixedDeltaTime())
	{
		fixedCounter -= GetPhysicsSystem()->GetFixedDeltaTime();
		GetPhysicsSystem()->Update();
		GetAudioSystem()->Update();
	}
}

void World::LateUpdate()
{
	for (int i = (int)markedtoDestroyGameObjects.size() - 1; i >= 0; i--)
	{
		DestroyGameObjectImmediate(markedtoDestroyGameObjects[i]);
	}
}

Object* World::CreateGameObject()
{
	Object* newObject = new Object();
	gameObjects.push_back(newObject);
	return newObject;
}

Object* World::CreateGameObject(std::string name)
{
	Object* newNamedObject = new Object(name);
	gameObjects.push_back(newNamedObject);
	return newNamedObject;
}

void World::DestroyGameObject(Object* gameObject)
{
	markedtoDestroyGameObjects.push_back(gameObject);
}

void World::Clear()
{
	for (int i = (int)gameObjects.size() - 1; i >= 0; i--)
	{
		DestroyGameObjectImmediate(gameObjects[i]);
	}
}

void World::Print() const
{
	for (auto& obj : gameObjects)
	{
		if (obj == nullptr)
			continue;
		
		if (obj->GetComponent<TransformComponent>()->GetParent() == nullptr)
		{
			obj->Print();
		}
	}
}

void World::DestroyGameObjectImmediate(Object* gameObject)
{
	gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [gameObject](Object* obj) {return obj == gameObject; }), gameObjects.end());
	markedtoDestroyGameObjects.erase(std::remove_if(markedtoDestroyGameObjects.begin(), markedtoDestroyGameObjects.end(), [gameObject](Object* obj) {return obj == gameObject; }), markedtoDestroyGameObjects.end());

	delete gameObject;
}
