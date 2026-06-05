#pragma once
#include "CoreMinimal.h"

namespace RoguelikeGame
{
	enum class ECollisionPreset
	{
		Ignore,
		Overlap,
		Block
	};

	class Object
	{
	private:
		bool markedToRemove = false;
		bool isVisible = true;

	protected:
		sf::Sprite ObjectSprite;
		sf::Vector2f ObjectPosition;
		ECollisionPreset CollisionPreset = ECollisionPreset::Block;

	public:
		Object(sf::Vector2f Position);
		virtual ~Object() {}

		virtual void Update(float DeltaTime);
		virtual void OnCollision(Object* otherObject);

		void SetSize(float sizeX, float sizeY);
		void Draw(sf::RenderWindow& window);

		void Move(sf::Vector2f offset);

		sf::FloatRect GetBounds();
		sf::Vector2f GetPosition();
		void SetPosition(sf::Vector2f newPos);

		void MarkToRemove();
		bool isMarkedToRemove();

		void Hide();
		void Unhide();
		bool IsVisibile();

		ECollisionPreset GetCollisionPreset();
	};
}


