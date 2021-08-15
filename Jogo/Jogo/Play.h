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

    Player* player;

    void run();

    void goToLevel(LevelTest* level);


public:
	Play();
	~Play();

};

