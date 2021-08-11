#pragma once
#include "Enemy.h"
#include "Player.h"

class Goblun :
    public Enemy
{
private:

    

public:
    Goblun(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* id = nullptr, Player* p = nullptr);
    ~Goblun();

    void update() override;

    void initVariables();

    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim) override;

    void updateMovement(); 
};