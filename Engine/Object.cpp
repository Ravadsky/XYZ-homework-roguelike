#include "pch.h"

#include "Object.h"
#include "Component.h"
#include "TransformComponent.h"

	Object::Object()
	{
		AddComponent<TransformComponent>();
	}

	Object::~Object()
	{
		for (auto& component : components)
			delete component;
		components.clear();
	}

	void Object::Update(float deltaTime)
	{
		for (auto& component : components)
			component->Update(deltaTime);
	}

	void Object::Render()
	{
		for (auto& component : components)
			component->Render();
	}
