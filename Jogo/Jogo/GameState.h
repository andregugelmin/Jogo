#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "MainMenuState.h"
#include "LevelTest.h"
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

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _car;

		sf::RectangleShape dangerzone;

		int _gameState;

		sf::Clock clock;

		GraphicsManager graphicsManager;

		LevelTest levelTest;

		Player* player;

		void run();


	};
}