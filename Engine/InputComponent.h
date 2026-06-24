#pragma once
#include "EngineAPI.h"
#include "Component.h"

class ENGINE_API InputComponent :
    public Component
{
public:
    InputComponent(Object* gameObject);

    virtual void Update(float deltaTime) override;
    virtual void Render() override;

    float getHorizontalAxis() const;
    float getVerticalAxis() const;

private:
    float horizontalAxis = 0.f;
    float verticalAxis = 0.f;
};

