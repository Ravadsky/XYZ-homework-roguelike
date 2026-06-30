#pragma once
#include "EngineAPI.h"
#include "Component.h"
#include "Vector.h"

class TransformComponent;

class ENGINE_API SpriteRendererComponent :
    public Component
{
public:
    SpriteRendererComponent(Object* gameObject);
    ~SpriteRendererComponent();

    virtual void Update(float deltaTime) override;
    virtual void Render() override;

    const sf::Sprite* GetSprite() const;
    void SetTexture(const sf::Texture& newTexture);
    void SetPixelSize(int newWidth, int newHeight);

    void FlipX(bool flip);
    void FlipY(bool flip);

private:
    Vector2Df scale;
    sf::Sprite* sprite;
    TransformComponent* transform;
   
    bool isFlipX = false;
    bool isFlipY = false;
};

