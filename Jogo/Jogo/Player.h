#pragma once
#include "Entidade.h"

class Player :
    public Entidade
{
private:
    float horizontalSpeed = 0, verticalSpeed = 0;
    sf::Vector2f position;
    void initTextura();
    void initSprite();

public:
    Player();
    ~Player();
    void move();
    sf::Vector2f getPosition();
};