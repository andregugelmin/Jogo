#pragma once
#include "Enemy.h"

class GiantBat: public Enemy
{
private:
    float attackCooldown;
    float attackCooldownMax;
    float attackRange;
    int shoots;
public:
    GiantBat(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* id = nullptr, Player* p = nullptr);
    ~GiantBat();

    void update() override;

    void initVariables();

    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim) override;

    void updateMovement();

    void shoot(sf::Vector2f targetPos);
};

