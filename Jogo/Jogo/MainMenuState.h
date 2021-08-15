#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <SFML/Audio.hpp>

namespace Nightmare {
    class MainMenuState : public State
    {
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
    };
}
