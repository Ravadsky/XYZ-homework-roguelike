#pragma once
#include "EngineAPI.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

class TransformComponent;
class Component;

class ENGINE_API Object
{
public:
	Object();
	~Object();

	virtual void Update(float DeltaTime);
	virtual void Render();

	template <typename T>
	T* AddComponent()
	{
		if constexpr (!std::is_base_of<Component, T>::value)
		{
			std::cout << "Class must be derived from component" << std::endl;
			return nullptr;
		}
		if constexpr (std::is_same<T, TransformComponent>::value)
		{
			if (GetComponent<TransformComponent>() != nullptr)
			{
				std::cout << "cant add transform, because it will break the engine loop" << std::endl;
				return nullptr;
			}
		}
		T* newComponent = new T(this);
		components.push_back(newComponent);
		std::cout << "Add new component: " << newComponent << std::endl;
		return newComponent;
	}

	template <typename T>
	void RemoveComponent(Component* component)
	{
		components.erase(std::remove_if(components.begin(), components.end(), [component](Component* obj) {return obj == component;}), components.end());
		delete component;
		std::cout << "Deleted component";
	}

	template <typename T>
	T* GetComponent() const
	{
		for (const auto& component : components)
		{
			if (auto casted = dynamic_cast<T*>(component))
			{
				return casted;
			}
		}
		return nullptr;
	}

private:
	std::vector<Component*> components = {};
};


