#include "AssetController.h"

namespace RoguelikeGame
{
	AssetController* AssetController::Instance()
	{
		static AssetController instance;
		return &instance;
	}

	sf::Font& AssetController::GetFont()
	{
		return font;
	}

	AssetController::AssetController()
	{
		assert(font.loadFromFile(FONTS_PATH + "Font.otf"));
		// Init textures
		//assert(TextureA.loadFromFile(TEXTURES_PATH + ".png"));
		// Init sounds
		//assert(SoundBufferA.loadFromFile(SOUNDS_PATH + ".wav"));

	}
}

