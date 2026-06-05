// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include "CoreMinimal.h"
#include "Application.h"

#include "Engine.h"
#include <Windows.h>
#include <iostream>

using namespace RoguelikeGame;

int main()
{
	if (AllocConsole())
	{
		FILE* fp;
		freopen_s(&fp, "CONOUT$", "w", stdout);
		freopen_s(&fp, "CONOUT$", "w", stderr);
	}
	else
	{
		std::cerr << "cannot capture console" << std::endl;
	}

	Engine engine;
	engine.Init(); engine.Run();

	Application::Instance().Run();

	return 0;
}
