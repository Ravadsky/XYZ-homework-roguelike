#pragma once
#include "Component.h"
#include "Vector.h"

class PursuitComponent :
    public Component
{
public:
    PursuitComponent(Object* gameObject);

    virtual void Update(float deltaTime) override;
    virtual void Render() override;

    void SetPursuitTarget(Object* target);
    Vector2Df GetTargetPosition();
    Vector2Df GetPursuitAxis();
private:
    Object* PursuitTarget;
};

