#pragma once
#include "EngineAPI.h"

class ENGINE_API Engine
{
public:
	static Engine* Instance();

	void Run();

	Engine(const Engine& app) = delete;
	Engine& operator=(const Engine&) = delete;
private:
	Engine();
	~Engine() = default;
};