#pragma once

#include <sstream>
#include "SplashState.h"
#include "Definitions.h"
#include "MainMenuState.h"

#include <iostream>

namespace Nightmare
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		this->_data->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// indo para o  menu
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			
		}
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);

		this->_data->window.display();
	}
}