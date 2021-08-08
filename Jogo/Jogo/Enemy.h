#pragma once
#include "Collider.h"
#include "Player.h"

class Enemy :
    public Collider
{
protected:
    float gravity;
    float drag;
    float airResistance;
    float velocityMaxY;
    float velocityMin;
    float acceleration;
    float velocityMaxX;

    Player* player;

public:
    Enemy(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr, Player* p = nullptr);
    ~Enemy();

    void resetVelocityY();

    void setTarget(Player* _player);

    void updateCollision(GraphicsManager* gm);
};

