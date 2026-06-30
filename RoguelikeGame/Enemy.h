#pragma once

class Object;

namespace RoguelikeGame
{
	class Enemy
	{
	public:
		Enemy();
		Object* GetGameObject();

	private:
		Object* gameObject;
	};
}