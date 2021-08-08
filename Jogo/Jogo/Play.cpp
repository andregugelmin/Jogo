#include "Play.h"
#include<iostream>

Play::Play(): graphicsManager(), levelTest(), current(GameState::LEVELTEST)
{
    levelTest.init(graphicsManager);
    play();
}

Play::~Play()
{

}


void Play::play()
{
    switch (current) {
    case GameState::LEVELTEST:
        
        levelTest.execute();
        break;
    }
}

void Play::goToLevel(LevelTest* level)
{

}


