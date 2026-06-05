#include "Object.h"

namespace RoguelikeGame
{
	Object::Object(sf::Vector2f Position)
	{
		SetSize(BASE_SPRITE_SCALE, BASE_SPRITE_SCALE);

		ObjectPosition = Position;
		ObjectSprite.setPosition(ObjectPosition);
	}

	void Object::Update(float DeltaTime)
	{
	}

	void Object::OnCollision(Object* otherObject)
	{

	}

	void Object::SetSize(float sizeX, float sizeY)
	{
		ObjectSprite.setScale(sf::Vector2f(sizeX, sizeY));
	}

	void Object::Draw(sf::RenderWindow& window)
	{
		window.draw(ObjectSprite);
	}

	void Object::Move(sf::Vector2f offset)
	{
		ObjectPosition += offset;
		ObjectSprite.setPosition(ObjectPosition);

	}

	sf::FloatRect Object::GetBounds()
	{
		return ObjectSprite.getGlobalBounds();
	}
	sf::Vector2f  Object::GetPosition()
	{
		return ObjectPosition;
	}
	void Object::SetPosition(sf::Vector2f newPos)
	{
		ObjectPosition = newPos;
		ObjectSprite.setPosition(ObjectPosition);
	}

	void Object::MarkToRemove()
	{
		markedToRemove = true;
	}
	bool Object::isMarkedToRemove()
	{
		return markedToRemove;
	}

	void Object::Hide()
	{
		isVisible = false;
	}

	void Object::Unhide()
	{
		isVisible = true;
	}

	bool Object::IsVisibile()
	{
		return isVisible;
	}
	
	ECollisionPreset Object::GetCollisionPreset()
	{
		return CollisionPreset;
	}
}

