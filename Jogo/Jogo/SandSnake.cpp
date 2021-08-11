#include<math.h>
#include "SandSnake.h"
#include "LevelTest.h"
#include <iostream>

SandSnake::SandSnake(sf::Vector2f pos, sf::Vector2f vel, const char* id, Player* p):
    Enemy(pos, vel, "Textures/Enemy2.png", id, p)
{
    initVariables();
}

SandSnake::~SandSnake()
{
}

void SandSnake::initVariables()
{
    gravity = 2.f;
    velocityMaxY = 15.f;
    airResistance = 0.8f;
    velocityMin = 0.5f;
    attackCooldown = 50.f;
    attackCooldownMax = 100.f;
    attackRange = 500.f;
    numLife = 3;
    hitCooldown = 0;
}

void SandSnake::update()
{
    if (level != nullptr) {
        updateCollision(level->getGraphicsManager());
    }

    if (attackCooldown < attackCooldownMax) {
        attackCooldown += 0.5;
    }

    if (player) {
        sf::Vector2f targetPos = player->getPosition();
        sf::Vector2f thisPos = getPosition();
        sf::Vector2f distance =(targetPos - thisPos);
        float range = sqrt((distance.x * distance.x) + (distance.y * distance.y));

        if(range<=attackRange)  shoot(targetPos);
    }

    if (hitCooldown>0) {
        hitCooldown--;       
    }
}


void SandSnake::shoot(sf::Vector2f targetPos)
{
    if (level != nullptr && attackCooldown>=attackCooldownMax) {
        level->spawnElement(new Projectile(position, "Textures/Projectile.png", "bullet", targetPos, 12.f, 100.f));
        attackCooldown = 0.f;
    }
}

void SandSnake::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{
    if (otherId == "PlayerProjectile" && hitCooldown<=0) {        
        hitCooldown = 10;
        numLife--;
        if (numLife <= 0) {
            setDead();
        }
    }
}


