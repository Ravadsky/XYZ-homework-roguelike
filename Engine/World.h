#pragma once
#include "EngineAPI.h"

#include <vector>

class Object;

class ENGINE_API World
{
public:
	static World* Instance();

	virtual void Update(float deltaTime);
	virtual void Render();
	
	void LateUpdate();

	Object* CreateGameObject();
	void DestroyGameObject(Object* gameObject);
	void Clear();

private:
	World() {}
	~World() {}

	World(World const&) = delete;
	World& operator=(World const&) = delete;

	std::vector<Object*> gameObjects = {};
	std::vector<Object*> markedtoDestroyGameObjects = {};

	void DestroyGameObjectImmediate(Object* gameObject);
};

