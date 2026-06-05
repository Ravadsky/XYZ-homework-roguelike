#pragma once
#include "CoreMinimal.h"

#define GetAssetController() AssetController::Instance()
#define GetAssetFont() AssetController::Instance()->GetFont()

namespace RoguelikeGame
{
	class AssetController
	{
	private:
		sf::Font font;

		// Resources
		sf::Texture TextureA;

		sf::SoundBuffer SoundBufferA;


	public:
		AssetController();

		AssetController(const AssetController& app) = delete;
		AssetController& operator= (const AssetController&) = delete;

		static AssetController* Instance();

		sf::Font& GetFont();
	};


}


