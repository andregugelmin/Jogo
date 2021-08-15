#pragma once

#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "MainMenuState.h"
#include <iostream>

using namespace sf;

namespace Nightmare
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{

		player = new Player(sf::Vector2f(200.f, 0.f), "player");
		levelManager.setPlayer(player);
		levelManager.init(_data->assets);
		run();

		_gameState = GameStates::eReady;

	}

	void GameState::HandleInput()
	{
		//nao funciona
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (GameStates::eGameOver != _gameState)
			{
				_gameState = GameStates::ePlaying;
			}

			if (sf::Event::KeyReleased == event.type)
			{
				if (sf::Keyboard::P == event.key.code)
				{
					// Switch To Pause
					this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
				}
			}

		}

	}

	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != _gameState)
		{

		}

		if (GameStates::ePlaying == _gameState)
		{
			//condicional de game over
					_gameState = GameStates::eGameOver;

		}

		if (GameStates::eGameOver == _gameState)
		{
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}
		}

	}

	void GameState::Draw(float dt)
	{
		/*this->_data->window.clear(sf::Color::White);*/

	}
	void GameState::run()
	{
		levelManager.execute();
	}
}