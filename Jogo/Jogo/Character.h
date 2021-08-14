#pragma once
#include "Collider.h"

class Character :
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

    int numLife;

    bool takeHit;
    float hitCooldown;

    bool onGround;

public:
    Character(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr);
    virtual ~Character();

    void move(const float x, const float y);
    void updatePhysics() override;

    void setDead();

    void resetVelocityY();
    virtual void updateCollision(GraphicsManager* gm);

};

