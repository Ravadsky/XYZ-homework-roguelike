#pragma once
#include "SFML/graphics.hpp"

class ColliderComponent;

class Collision
{
public:
	Collision(ColliderComponent* newFirst, ColliderComponent* newSecond, sf::FloatRect newCollisionRect)
		: first(newFirst), second(newSecond), collisionRect(newCollisionRect) {};
private:
	ColliderComponent* first;
	ColliderComponent* second;
	sf::FloatRect collisionRect;
};

