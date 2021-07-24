#pragma once
#include "Entidade.h"

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING, ATACKING };

class Player :
    public Entidade
{
private:
    float horizontalSpeed, verticalSpeed;
    sf::Vector2f position;
    sf::Clock animationTimer;

    //Inicializacao
    void initVariables();
    void initTextura();
    void initSprite();
    void initAnimations();

    //Animacao
    short animState;
    sf::IntRect currentFrame;

public:
    Player();
    ~Player();

   
    void updateMovement();
    void updateAnimations();
    void update();

    sf::Vector2f getPosition();
};