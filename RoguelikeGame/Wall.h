#pragma once

class Object;

namespace RoguelikeGame
{
	class Wall
	{
	public:
		Wall();
		Object* GetGameObject();

	private:
		Object* gameObject;
	};
}
