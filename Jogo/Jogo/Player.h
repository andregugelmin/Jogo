#pragma once
#include "Collider.h"


class Player :
    public Collider
{
private:
    
    float acceleration;
    float gravity;
    float drag;
    float airResistance;
    float velocityMin;
    float velocityMaxX;
    float velocityMaxY;

    bool onGround;  

public:
    Player(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* id = nullptr);
    ~Player();

    //Inicializacao
    void init(GraphicsManager& gm, CollisionManager& cm);
    void initVariables();


    //Functions
    void update(GraphicsManager& gm);
    void draw(GraphicsManager& gm);


    void move(const float x, const float y);
    void resetVelocityY();

    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim);

    //Updates
    void updatePhysics();
    void updateMovement();
    void updateCollision(GraphicsManager& gm);

    //Getters
    sf::Vector2f getPosition();

    //Setters
    void setPosition(const float x, const float y);
};