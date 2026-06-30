#include "pch.h"
#include "ColliderComponent.h"
#include "AudioSystem.h"

ColliderComponent::ColliderComponent(Object* gameObject) : Component(gameObject)
{
}

void ColliderComponent::SetTrigger(bool newIsTrigger)
{
	isTrigger = newIsTrigger;
}

void ColliderComponent::SubscribeCollision(std::function<void(Collision)> onCollisionAction)
{
	onCollisionActions.push_back(onCollisionAction);
}

void ColliderComponent::UnsubscribeCollision(std::function<void(Collision)> onCollisionAction)
{
	onCollisionActions.erase(std::remove_if
	(
		onCollisionActions.begin(), onCollisionActions.end(),
		[&onCollisionAction](const std::function<void(Collision)>& action)
		{
			return action.target<void(Collision)>() == onCollisionAction.target<void(Collision)>();
		}
	), onCollisionActions.end());
}

void ColliderComponent::SubscribeCTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction)
{
	onTriggerEnterActions.push_back(onTriggerEnterAction);

}

void ColliderComponent::UnsubscribeCTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction)
{
	onTriggerEnterActions.erase(std::remove_if
	(
		onTriggerEnterActions.begin(), onTriggerEnterActions.end(),
		[&onTriggerEnterAction](const std::function<void(Trigger)>& action)
		{
			return action.target<void(Trigger)>() == onTriggerEnterAction.target<void(Trigger)>();
		}
	), onTriggerEnterActions.end());
}

void ColliderComponent::SubscribeCTriggerExit(std::function<void(Trigger)> onTriggerExitActon)
{
	onTriggerExitActions.push_back(onTriggerExitActon);

}

void ColliderComponent::UnsubscribeCTriggerExit(std::function<void(Trigger)> onTriggerExitAction)
{
	onTriggerExitActions.erase(std::remove_if
	(
		onTriggerExitActions.begin(), onTriggerExitActions.end(),
		[&onTriggerExitAction](const std::function<void(Trigger)>& action)
		{
			return action.target<void(Trigger)>() == onTriggerExitAction.target<void(Trigger)>();
		}
	), onTriggerExitActions.end());
}

void ColliderComponent::OnCollision(Collision collision)
{
	for (int i = 0; i < onCollisionActions.size(); i++)
		onCollisionActions[i](collision);

	// Временная обработка звуков при коллизии
	GetAudioSystem()->PlaySound("Hit");
}

void ColliderComponent::OnTriggerEnter(Trigger trigger)
{
	for (int i = 0; i < onTriggerEnterActions.size(); i++)
		onTriggerEnterActions[i](trigger);
}

void ColliderComponent::OnTriggerExit(Trigger trigger)
{
	for (int i = 0; i < onTriggerExitActions.size(); i++)
		onTriggerExitActions[i](trigger);
}
