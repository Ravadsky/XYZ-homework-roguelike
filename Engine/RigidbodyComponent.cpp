#include "pch.h"
#include "RigidbodyComponent.h"
#include "Object.h"

	RigidbodyComponent::RigidbodyComponent(Object* gameObject) : Component(gameObject)
	{
		transform = gameObject->GetComponent<TransformComponent>();
	}

	void RigidbodyComponent::Update(float deltaTime)
	{
		transform->MoveBy(linearVelocity);
		transform->RotateBy(angleVelocity);

		linearVelocity = linearVelocity * (1.f - linearDamping * deltaTime);
		angleVelocity = angleVelocity   * (1.f - angleDamping * deltaTime);

		if (linearVelocity.x < 0.001f)
		{
			linearVelocity = { 0.f, linearVelocity.y };
		}
		if (linearVelocity.y < 0.001f)
		{
			linearVelocity = { linearVelocity.x, 0.f };
		}

		if (angleVelocity < 0.001f)
		{
			angleVelocity = 0.f;
		}
	}
	void RigidbodyComponent::Render()
	{
	}

	void RigidbodyComponent::SetLinearVelocity(Vector2Df newLinearVelocity)
	{
		linearVelocity = newLinearVelocity;
	}
	void RigidbodyComponent::AddLinearVelocity(Vector2Df linearOffset)
	{
		linearVelocity = linearVelocity + linearOffset;
	}
	Vector2Df RigidbodyComponent::GetLinearVelocity() const
	{
		return linearVelocity;
	}

	void RigidbodyComponent::SetAngleVelocity(float newAngleVelocity)
	{
		angleVelocity = newAngleVelocity;
	}
	void RigidbodyComponent::AddAngleVelocity(float angleOffset)
	{
		angleVelocity += angleOffset;
	}
	float RigidbodyComponent::GetAngleVelocity() const
	{
		return angleVelocity;
	}

	void RigidbodyComponent::SetLinearDamping(float newLinearDamping)
	{
		linearDamping = newLinearDamping;
	}
	float RigidbodyComponent::GetLinearDamping() const
	{
		return linearDamping;
	}

	void RigidbodyComponent::SetAngleDamping(float newAngleDamping)
	{
		angleDamping = newAngleDamping;
	}
	float RigidbodyComponent::GetAngleDamping() const
	{
		return angleDamping;
	}

	void RigidbodyComponent::SetKinematic(bool newIsKinematic)
	{
		isKinematic = newIsKinematic;
	}
	bool RigidbodyComponent::GetKinematic() const
	{
		return isKinematic;
	}