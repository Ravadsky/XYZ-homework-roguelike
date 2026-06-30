#include "pch.h"
#include "CharacterMovementComponent.h"
#include "Object.h"
#include "TransformComponent.h"
#include "InputComponent.h"
#include "PursuitComponent.h"

CharacterMovementComponent::CharacterMovementComponent(Object* gameObject) : Component(gameObject)
{
}

void CharacterMovementComponent::Update(float deltaTime)
{
	auto transform = GameObject->GetComponent<TransformComponent>();

	Vector2Df movementVector;

	auto input = GameObject->GetComponent<InputComponent>();
	if (input != nullptr)
	{
		movementVector = movementVector + Vector2Df(input->getHorizontalAxis(), input->getVerticalAxis());
	}

	auto pursuit = GameObject->GetComponent<PursuitComponent>();
	if (pursuit != nullptr)
	{
		movementVector = movementVector + pursuit->GetPursuitAxis();
	}

	transform->MoveBy(movementVector * deltaTime * movementSpeed);
}

void CharacterMovementComponent::Render()
{
}

void CharacterMovementComponent::SetMovementSpeed(float newSpeed)
{
	movementSpeed = newSpeed;
}
