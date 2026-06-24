#include "pch.h"
#include "CameraComponent.h"

#include "Object.h"
#include "TransformComponent.h"
#include <iostream>
#include "Vector.h"

CameraComponent::CameraComponent(Object* gameObject) : Component(gameObject)
{
	view = new sf::View(sf::FloatRect(0, 0, 800, -600));
	transform = gameObject->GetComponent<TransformComponent>();
}

CameraComponent::~CameraComponent()
{
	delete view;
}

void CameraComponent::Update(float deltaTime)
{
	auto position = transform->GetWorldPosition();
	auto rotation = transform->GetWorldRotaton();

	view->setCenter(Convert<sf::Vector2f, Vector2Df>(position));
	view->setRotation(rotation);

	window->setView(*view);
}

void CameraComponent::Render()
{
	if (window == nullptr)
	{
		std::cout << "NULL RENDER WINDOW" << std::endl;
	}
}

void CameraComponent::SetWindow(sf::RenderWindow* newWindow)
{
	window = newWindow;
}

void CameraComponent::ZoomBy(float newZoom)
{
	if (newZoom <= 0)
	{
		std::cout << "not allowed zoom lesser or equal than zero" << std::endl;
	}
	view->zoom(newZoom);
}

void CameraComponent::SetBaseResolution(int width, int height)
{
	view->reset(sf::FloatRect(0, 0, (float)width, -(float)height));
}
