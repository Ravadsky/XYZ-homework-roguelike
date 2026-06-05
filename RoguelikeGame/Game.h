#pragma once
#include "CoreMinimal.h"

namespace RoguelikeGame
{
	class GameStateBase;

	enum class GameStateChangeType
	{
		None,
		Push, Pop, Switch
	};

	enum class GameStateType
	{
		None,
		GameOver, MainMenu, PauseMenu, Playing, ExitDialog,
	};

	struct GameStateContext
	{
		GameStateChangeType stateChangeType = GameStateChangeType::None;
		GameStateType pendingGameStateType = GameStateType::None;
		bool pendingGameStateIsExclusivelyVisible = false;

		void Reset();
		void Set(GameStateChangeType ChangeType, GameStateType StateType, bool isExclusivelyVisible = false);
	};

	class GameState
	{
	private:
		GameStateType type = GameStateType::None;
		std::unique_ptr<GameStateBase> data;
		bool isExclusivelyVisible = false;

	public:
		GameState(GameStateType GameType, bool pendingIsExclusivelyVisible);

		void Shutdown();
		void HandleWindowEvent(sf::Event& event);
		void Update(float timeDelta);
		void Draw(sf::RenderWindow& window);
		bool isStateExclusivelyVisible();
	};

	class Game
	{
	private:
		std::vector<GameState> stateStack;

		GameStateContext PendingContext;

	public:
		Game();
		~Game();

		void HandleWindowEvents(sf::RenderWindow& window);
		bool Update(float timeDelta);
		void Draw(sf::RenderWindow& window);

		void PushState(GameStateType stateType, bool isExclusivelyVisible);
		void SwitchStateTo(GameStateType newState);
		void PopState();
	};

}
