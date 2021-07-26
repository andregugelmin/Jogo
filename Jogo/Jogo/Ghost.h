#pragma once
#include "Entidade.h"
#include "Player.h"

class Game;

//enum ENEMY_ANIMATION_STATES { EIDLE = 0, EMOVING_LEFT, EMOVING_RIGHT };

class Ghost :
    public Entidade
{
private:

    float horizontalSpeed;
    float gravity;
    float drag;
    float airResistance;
    float velocityMaxY;
    float velocityMin;
    float acceleration;
    float velocityMaxX;

    Player* player;
    sf::Vector2f targetPos;
    sf::Vector2f thisPos;
    sf::Vector2f velocity;
    sf::Clock animationTimer;

    void initVariables();
    void initTextura();
    void initSprite();    
    void initPhysics();
    void initAnimations();

    //Animacao
    short animState;
    sf::IntRect currentFrame;

public:
    Ghost();
    ~Ghost();

    
    void resetVelocityY();
    void followPlayer();
    void move(const float x, const float y);

    //Getters
    sf::Vector2f getPosition();
    sf::Vector2f getMidPosition();
    const sf::FloatRect getGlobalBounds() const;

    //Setters
    void setTarget(Player* _player);
    void setPosition(const float x, const float y);

    //Updates    
    void updatePhysics();
    void updateMovement();
    void updateAnimations();
    void updateCollision();
    void update();
};