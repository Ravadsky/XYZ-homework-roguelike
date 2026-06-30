#pragma once
#include "EngineAPI.h"

#include <vector>
#include <string>

#define GetWorld() World::Instance()

class Object;

class ENGINE_API World
{
public:
	static World* Instance();

	virtual void Update(float deltaTime);
	virtual void Render();

	void FixedUpdate(float deltaTime);
	void LateUpdate();

	Object* CreateGameObject();
	Object* CreateGameObject(std::string name);
	void DestroyGameObject(Object* gameObject);
	void Clear();

	void Print() const;
private:
	World() {}
	~World() {}

	World(World const&) = delete;
	World& operator=(World const&) = delete;

	float fixedCounter = 0.0f;

	std::vector<Object*> gameObjects = {};
	std::vector<Object*> markedtoDestroyGameObjects = {};

	void DestroyGameObjectImmediate(Object* gameObject);
};

