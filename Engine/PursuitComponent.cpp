#include "pch.h"
#include "PursuitComponent.h"
#include "Object.h"
#include "TransformComponent.h"

PursuitComponent::PursuitComponent(Object* gameObject) : Component(gameObject)
{
}

void PursuitComponent::Update(float deltaTime)
{
}

void PursuitComponent::Render()
{
}

void PursuitComponent::SetPursuitTarget(Object* target)
{
	std::cout << "Target for pursuit" << this << "was set : " << target << std::endl;
	PursuitTarget = target;
	std::cout << PursuitTarget << std::endl;

}

Vector2Df PursuitComponent::GetTargetPosition()
{
	auto TargetTransform = PursuitTarget->GetComponent<TransformComponent>();

	return TargetTransform->GetWorldPosition();;
}

Vector2Df PursuitComponent::GetPursuitAxis()
{
	if (PursuitTarget != nullptr)
	{
		auto Transform = GameObject->GetComponent<TransformComponent>();

		Vector2Df selfPosition = Transform->GetWorldPosition();
		Vector2Df offset = GetTargetPosition() - selfPosition;
		return Vector2Df(offset.Normalize());
	}
	else
		return Vector2Df(0.0f, 0.0f);
}
