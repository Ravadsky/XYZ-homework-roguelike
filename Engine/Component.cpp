#include "pch.h"
#include "Component.h"

#include <iostream>

Component::Component(Object* gameObject) : GameObject(gameObject)
{
}

Component::~Component()
{
	std::cout << "Component was deleted: " << this << std::endl;
}

Object* Component::GetGameObject()
{
	return GameObject;
}
