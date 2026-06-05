#include "Game.h"
#include <algorithm>

#include "GameStatePlaying.h"
#include "GameStateGameOver.h"
#include "GameStatePauseMenu.h"
#include "GameStateMainMenu.h"

namespace RoguelikeGame
{
	Game::Game()
	{
		SwitchStateTo(GameStateType::MainMenu);
	}

	Game::~Game()
	{
		while (stateStack.size() > 0)
		{
			stateStack.back().Shutdown();
			stateStack.pop_back();
		}

		PendingContext.Reset();
	}

	void Game::HandleWindowEvents(sf::RenderWindow& window)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window if close button or Escape key pressed
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (stateStack.size() > 0)
			{
				stateStack.back().HandleWindowEvent(event);
			}
		}
	}

	bool Game::Update(float timeDelta)
	{
		if (PendingContext.stateChangeType == GameStateChangeType::Switch)
		{
			// Shutdown all game states
			while (stateStack.size() > 0)
			{
				stateStack.back().Shutdown();
				stateStack.pop_back();
			}
		}
		else if (PendingContext.stateChangeType == GameStateChangeType::Pop)
		{
			// Shutdown only current game state
			if (stateStack.size() > 0)
			{
				stateStack.back().Shutdown();
				stateStack.pop_back();
			}
		}

		// Initialize new game state if needed
		if (PendingContext.pendingGameStateType != GameStateType::None)
		{
			stateStack.emplace_back(PendingContext.pendingGameStateType, PendingContext.pendingGameStateIsExclusivelyVisible);
		}

		PendingContext.Reset();

		if (stateStack.size() > 0)
		{
			stateStack.back().Update(timeDelta);
			return true;
		}

		return false;
	}

	void Game::Draw(sf::RenderWindow& window)
	{
		if (stateStack.size() > 0)
		{
			std::vector<GameState*> visibleGameStates;

			for (auto it = stateStack.rbegin(); it != stateStack.rend(); ++it)
			{
				visibleGameStates.push_back(&(*it));
				if (it->isStateExclusivelyVisible())
				{
					break;
				}
			}

			for (auto it = visibleGameStates.rbegin(); it != visibleGameStates.rend(); ++it)
			{
				(**it).Draw(window);
			}
		}
	}

	void Game::PushState(GameStateType stateType, bool isExclusivelyVisible)
	{
		PendingContext.Set(GameStateChangeType::Push, stateType, isExclusivelyVisible);
	}

	void Game::PopState()
	{
		PendingContext.Set(GameStateChangeType::Pop, GameStateType::None, false);
	}

	void Game::SwitchStateTo(GameStateType newState)
	{
		PendingContext.Set(GameStateChangeType::Switch, newState, false);
	}

	// GameState

	GameState::GameState(GameStateType GameType, bool pendingIsExclusivelyVisible)
	{
		type = GameType;
		isExclusivelyVisible = pendingIsExclusivelyVisible;
		switch (type)
		{
		case GameStateType::MainMenu:
		{
			data = std::make_unique<GameStateMainMenuData>();
			break;
		}
		case GameStateType::Playing:
		{
			data = std::make_unique<GameStatePlayingData>();
			break;
		}
		case GameStateType::GameOver:
		{
			data = std::make_unique<GameStateGameOverData>();
			break;
		}
		case GameStateType::ExitDialog:
		{
			data = std::make_unique<GameStatePauseMenuData>();
			break;
		}

		default:
			assert(false); // We want to know if we forgot to implement new game state
			break;
		}
	}

	void GameState::Shutdown()
	{
		
	}

	void GameState::HandleWindowEvent(sf::Event& event)
	{
		if (data)
		{
			data->HandleWindowEvent(event);
		}
	}

	void GameState::Update(float timeDelta)
	{
		if (data)
		{
			data->Update(timeDelta);
		}
	}

	void GameState::Draw(sf::RenderWindow& window)
	{
		if (data)
		{
			data->Draw(window);
		}
	}

	bool GameState::isStateExclusivelyVisible()
	{
		return isExclusivelyVisible;
	}

	// GameStateContext

	void GameStateContext::Reset()
	{
		stateChangeType = GameStateChangeType::None;
		pendingGameStateType = GameStateType::None;
		pendingGameStateIsExclusivelyVisible = false;
	}

	void GameStateContext::Set(GameStateChangeType ChangeType, GameStateType StateType, bool isExclusivelyVisible)
	{
		stateChangeType = ChangeType;
		pendingGameStateType = StateType;
		pendingGameStateIsExclusivelyVisible = isExclusivelyVisible;
	}
}
