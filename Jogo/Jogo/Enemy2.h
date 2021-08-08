#pragma once
#include "Enemy.h"
#include "Player.h"
#include"Projectile.h"

class Enemy2 :
    public Enemy
{
private:
    float attackCooldown;
    float attackCooldownMax;
    float attackRange;

public:
    Enemy2(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* id = nullptr, Player* p = nullptr);
    ~Enemy2();

    void update();
    void updatePhysics();

    void initVariables();
    void shoot(sf::Vector2f targetPos);
    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim);
  
    
};
