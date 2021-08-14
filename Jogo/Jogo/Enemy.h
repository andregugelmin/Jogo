#pragma once
#include "Character.h"
#include "Player.h"

class Enemy :
    public Character
{
protected:

    Player* player;

public:
    Enemy(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr, Player* p = nullptr);
    virtual ~Enemy();

    void setTarget(Player* _player);
};

