#pragma once
#include "Enemy.h"
#include "Player.h"

class Enemy1 :
    public Enemy
{
private:

    

public:
    Enemy1(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* id = nullptr, Player* p = nullptr);
    ~Enemy1();

    void update();

    void initVariables();

    void move(const float x, const float y);
    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim);

   
    void updatePhysics();
    void updateMovement(); 
};