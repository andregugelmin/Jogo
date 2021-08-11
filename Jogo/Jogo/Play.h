#pragma once
#include "LevelTest.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "Player.h"

class Play
{
private:
    enum class GameState {        
        LEVELTEST
    };

    GraphicsManager graphicsManager;

    LevelTest levelTest;

    GameState current;

    void play();

    void goToLevel(LevelTest* level);


public:
	Play();
	~Play();

};

