#pragma once

#include "TransformComponent.h"
#include "Vector.h"

class RigidbodyComponent : public Component
{
public:
	RigidbodyComponent(Object* gameObject);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	void SetLinearVelocity(Vector2Df newLinearVelocity);
	void AddLinearVelocity(Vector2Df linearOffset);
	Vector2Df GetLinearVelocity() const;

	void SetAngleVelocity(float newAngleVelocity);
	void AddAngleVelocity(float angleOffset);
	float GetAngleVelocity() const;

	void SetLinearDamping(float newLinearDamping);
	float GetLinearDamping() const;

	void SetAngleDamping(float newAngleDamping);
	float GetAngleDamping() const;

	void SetKinematic(bool newIsKinematic);
	bool GetKinematic() const;

private:
	TransformComponent* transform;

	Vector2Df linearVelocity = { 0.f, 0.f };
	float angleVelocity = 0.f;

	float linearDamping = 0.f;
	float angleDamping = 0.f;

	bool isKinematic = false;
};