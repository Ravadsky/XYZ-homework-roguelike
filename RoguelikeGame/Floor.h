#pragma once

class Object;

namespace RoguelikeGame
{
	class Floor
	{
	public:
		Floor();
		Object* GetGameObject();

	private:
		Object* gameObject;
	};
}
