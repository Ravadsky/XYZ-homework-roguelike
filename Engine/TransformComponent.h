#pragma once
#include "EngineAPI.h"
#include "Component.h"

#include "Vector.h"

class ENGINE_API TransformComponent :
    public Component
{
public:
    TransformComponent(Object* gameObject);

    virtual void Update(float deltaTime) override;
    virtual void Render() override;

    void MoveBy(const Vector2Df& offset);
    void RotateBy(float offset);
    void ScaleBy(const Vector2Df& scaleOffset);

    const Vector2Df GetWorldPosition() const;
    const float GetWorldRotaton() const;
    const Vector2Df GetWorldScale() const;

private:
    mutable Vector2Df position = { 0, 0 };
    mutable float rotation = 0.f;
    mutable Vector2Df scale = { 1, 1 };
};

