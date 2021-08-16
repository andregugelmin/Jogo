#pragma once
#include "LevelManager.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "Player.h"
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "GraphicsManager.h"
#include "InputManager.h"


namespace Nightmare
{
    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        GraphicsManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    private:
        enum class GameState {
            LEVELTEST
        };

        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData>();

        void Run();


        GameState current;



    public:
        Game(int width, int height, std::string title);
        sf::Image icon;

    };
}

