#pragma once

class Object;

namespace RoguelikeGame
{
	class Player
	{
	public:
		Player();
		Object* GetGameObject();

	private:
		Object* gameObject;
	};
}


