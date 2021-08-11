#pragma once
#include "Character.h"


class Player :
    public Character
{
private:

    float attackCooldown;
    float attackCooldownMax;

    int dir;

    bool onGround;  

public:
    Player(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* id = nullptr);
    ~Player();

    void initVariables();

    void update() override;
    void draw() override;

    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim) override;

    void updateMovement();
    void updateCollision(GraphicsManager* gm) override;
    void shoot();
};