#pragma once
#include "EngineAPI.h"

#include "Component.h"

class TransformComponent;

class ENGINE_API CameraComponent :
    public Component
{
public:
    CameraComponent(Object* gameObject);
    ~CameraComponent();

    virtual void Update(float deltaTime) override;
    virtual void Render() override;

    void SetWindow(sf::RenderWindow* newWindow);
    void ZoomBy(float newZoom);

    void SetBaseResolution(int width, int height);

private:
    TransformComponent* transform;
    sf::RenderWindow* window;
    sf::View* view;
};

