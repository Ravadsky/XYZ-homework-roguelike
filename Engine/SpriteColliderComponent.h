#pragma once
#include "ColliderComponent.h"

class Sprite;

class SpriteColliderComponent :
    public ColliderComponent
{
public:
    SpriteColliderComponent(Object* gameObject);
    ~SpriteColliderComponent();

    virtual void Update(float deltaTime) override;
    virtual void Render() override;

private:
    const sf::Sprite* sprite;
};

