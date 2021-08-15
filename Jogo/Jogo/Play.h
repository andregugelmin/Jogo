#pragma once
#include "LevelTest.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "Player.h"

class Play
{
private:
    enum class GameState {        
       MENU,
       LEVEL01,
       PAUSE,
       LEVELTEST
    };

    GraphicsManager graphicsManager;

    LevelTest levelTest;

    GameState current;

    Player* player;

    void play();

    void goToLevel(LevelTest* level);


public:
	Play();
	~Play();

};

