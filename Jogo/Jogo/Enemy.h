#pragma once
#include "Entidade.h"
#include "Player.h"

class Game;

class Enemy :
    public Entidade
{
private:
    Player* player;
    sf::Vector2f targetPos;
    sf::Vector2f thisPos;
    void initTextura();
    void initSprite();

public:
    Enemy();
    ~Enemy();
    void setTarget(Player* _player);
    void atualiza();
};