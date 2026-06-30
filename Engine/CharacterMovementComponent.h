#pragma once
#include "Component.h"
class CharacterMovementComponent :
    public Component
{
public:
    CharacterMovementComponent(Object* gameObject);

    virtual void Update(float deltaTime) override;
    virtual void Render() override;

    void SetMovementSpeed(float newSpeed);
private:
    float movementSpeed = 20.0f;
};

