#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "MainMenuState.h"
#include "LevelManager.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "Player.h"

namespace Nightmare
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		float currentFrame = 0;

		void run();

	private:
		GameDataRef _data;

		sf::Sprite _background;

		int _gameState;

		sf::Clock clock;

		LevelManager levelManager;

		Player* player;



	};
}