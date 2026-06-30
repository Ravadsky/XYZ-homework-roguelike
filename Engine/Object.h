#pragma once
#include "EngineAPI.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

class TransformComponent;
class Component;

class ENGINE_API Object
{
	friend TransformComponent;

public:
	Object();
	Object(std::string newName);

	~Object();

	virtual void Update(float DeltaTime);
	virtual void Render();

	std::string GetName() const;
	void Print(int depth = 0) const;

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

	void RemoveComponent(Component* component);

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

	template <typename T>
	T* GetComponentInChildren() const
	{
		T* component = GetComponent<T>();
		if (component != nullptr || children.size() == 0)
		{
			return component;
		}
		for (const auto& child : children)
		{
			T* childComponent = child->GetComponentInChildren<T>();
			if (childComponent != nullptr)
			{
				return childComponent;
			}
		}

		return nullptr;
	}

	template <typename T>
	std::vector<T*> GetComponents() const
	{
		std::vector<T*> result;
		for (const auto& component : components)
		{
			if (auto casted = dynamic_cast<T*>(component))
			{
				result.push_back(casted);
			}
		}
		return result;
	}

private:
	std::vector<Component*> components = {};
	std::string name;
	std::vector<Object*> children = {};

	void AddChild(Object* child);
	void RemoveChild(Object* child);
};


