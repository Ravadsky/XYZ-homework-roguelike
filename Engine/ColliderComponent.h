#pragma once
#include "Component.h"
#include <functional>

#include "Collision.h"
#include "Trigger.h"
#include "PhysicsSystem.h"
#include <vector>

class ColliderComponent :
    public Component
{
public:
    ColliderComponent(Object* gameObject);

    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;

    void SetTrigger(bool newIsTrigger);

    void SubscribeCollision(std::function<void(Collision)> onCollisionAction);
    void UnsubscribeCollision(std::function<void(Collision)> onCollisionAction);

    void SubscribeCTriggerEnter(std::function<void(Trigger) > onTriggerEnterAction);
    void UnsubscribeCTriggerEnter(std::function<void(Trigger) > onTriggerEnterAction);

    void SubscribeCTriggerExit(std::function<void(Trigger) > onTriggerExitAction);
    void UnsubscribeCTriggerExit(std::function<void(Trigger) > onTriggerExitAction);
    
    friend class PhysicsSystem;

protected:
    sf::FloatRect bounds;
    bool isTrigger = false;

    void OnCollision(Collision collision);
    void OnTriggerEnter(Trigger trigger);
    void OnTriggerExit(Trigger trigger);

    std::vector<std::function<void(Collision)>> onCollisionActions;
    std::vector<std::function<void(Trigger)>> onTriggerEnterActions;
    std::vector<std::function<void(Trigger)>> onTriggerExitActions;


};

