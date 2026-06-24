#pragma once
#include "EngineAPI.h"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Object;

class ENGINE_API Component
{
public:
	Component(Object* gameObject);
	virtual ~Component();

	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

	Object* GetGameObject();

protected:
	Object* GameObject;
};

