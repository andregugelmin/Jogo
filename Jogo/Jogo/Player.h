#pragma once
#include "Entidade.h"

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING, ATACKING };

class Player :
    public Entidade
{
private:
    
    float horizontalSpeed;
    float acceleration;
    float gravity;
    float drag;
    float airResistance;
    float velocityMin;
    float velocityMaxX;
    float velocityMaxY;

    bool onGround;

    sf::Vector2f velocity;
    sf::Clock animationTimer;

    //Inicializacao
    void initVariables();
    void initTextura();
    void initSprite();
    void initPhysics();
    void initAnimations();

    //Animacao
    short animState;
    sf::IntRect currentFrame;

public:
    Player();
    ~Player();

    //Functions
    void move(const float x, const float y);
    void resetVelocityY();

    //Updates
    void updatePhysics();
    void updateMovement();
    void updateAnimations();
    void updateCollision();
    void update();

    //Getters
    sf::Vector2f getPosition();
    sf::Vector2f getMidPosition();
    const sf::FloatRect getGlobalBounds() const;

    //Setters
    void setPosition(const float x, const float y);
};