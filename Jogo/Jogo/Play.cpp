#include "Play.h"
#include<iostream>

Play::Play(): graphicsManager(), levelTest()
{
    player = new Player(sf::Vector2f(200.f, 0.f), "player");
    levelTest.setPlayer(player);
    levelTest.init(graphicsManager);
    run();
}

Play::~Play()
{

}


void Play::run()
{
        levelTest.execute();
    
}

void Play::goToLevel(LevelTest* level)
{

}


