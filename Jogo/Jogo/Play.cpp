#include "Play.h"
#include<iostream>

Play::Play(): graphicsManager(), levelTest(), current(GameState::LEVELTEST)
{
    player = new Player(sf::Vector2f(200.f, 0.f), "player");
    levelTest.setPlayer(player);
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


