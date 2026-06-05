#pragma once
#include <string>

namespace RoguelikeGame
{
	// Resources path
	const std::string RESOURCES_PATH = "Resources/";
	const std::string TEXTURES_PATH = RESOURCES_PATH + "Textures/";
	const std::string FONTS_PATH = RESOURCES_PATH + "Fonts/";
	const std::string SOUNDS_PATH = RESOURCES_PATH + "Sounds/";

	// Game Window
	const unsigned int SCREEN_WIDTH = 1280;
	const unsigned int SCREEN_HEGHT = 720;
	const std::string GAME_NAME = "Rogelike";

	// System
	const float TIME_PER_FRAME = 1.f / 60.f; // 60 fps
	const float BASE_SPRITE_SCALE = 4.f;

	// Player Parameters
	const float PLAYER_BASE_SPEED = 20.f;
}
