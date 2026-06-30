#include "pch.h"

#include "Object.h"
#include "Component.h"
#include "TransformComponent.h"

	Object::Object()
	{
		name = "GameObject";
		AddComponent<TransformComponent>();
	}

	Object::Object(std::string newName)
	{
		name = newName;
		AddComponent<TransformComponent>();
	}

	Object::~Object()
	{
		for (auto& component : components)
			delete component;

		components.clear();
		children.clear();
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

	std::string Object::GetName() const
	{
		return name;
	}

	void Object::Print(int depth) const
	{
		std::cout << std::string(depth * 2, ' ') << GetName() << std::endl;
		for (auto& component : components)
		{
			std::cout << std::string(depth * 2, ' ') << "::" << component << std::endl;
		}
		for (Object* child : children)
		{
			child->Print(depth + 1);
		}
	}

	void Object::RemoveComponent(Component* component)
	{
		components.erase(std::remove_if(components.begin(), components.end(), [component](Component* obj) {return obj == component;}), components.end());
		delete component;
		std::cout << "Deleted component";
	}

	void Object::AddChild(Object* child)
	{
		children.push_back(child);
	}

	void Object::RemoveChild(Object* child)
	{
		auto remover = [child](Object* obj) {return obj == child; };
		children.erase(std::remove_if(children.begin(), children.end(), remover), children.end());

	}
