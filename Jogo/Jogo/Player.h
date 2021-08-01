#pragma once
#include "Entity.h"


class Player :
    public Entity
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

public:
    Player(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
    ~Player();

    //Inicializacao
    void init(GraphicsManager& gm);
    void initVariables();


    //Functions
    void update(GraphicsManager& gm);
    void draw(GraphicsManager& gm);

    void move(const float x, const float y);
    void resetVelocityY();


    //Updates
    void updatePhysics();
    void updateMovement();
    void updateCollision(GraphicsManager& gm);

    //Getters
    sf::Vector2f getPosition();
    sf::Vector2f getMidPosition();

    //Setters
    void setPosition(const float x, const float y);
};