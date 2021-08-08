#include<math.h>
#include "Enemy2.h"
#include "LevelTest.h"

Enemy2::Enemy2(sf::Vector2f pos, sf::Vector2f vel, const char* id, Player* p):
    Enemy(pos, vel, "Textures/Enemy2.png", id, p)
{
    initVariables();
}

Enemy2::~Enemy2()
{
}

void Enemy2::initVariables()
{
    gravity = 2.f;
    velocityMaxY = 15.f;
    airResistance = 0.8f;
    velocityMin = 0.5f;
    attackCooldown = 50.f;
    attackCooldownMax = 100.f;
    attackRange = 500.f;
}

void Enemy2::update()
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
}


void Enemy2::shoot(sf::Vector2f targetPos)
{
    if (level != nullptr && attackCooldown>=attackCooldownMax) {
        level->spawnElement(new Projectile(position, sf::Vector2f(0.f, 0.f), "Textures/Projectile.png", "bullet", targetPos));
        attackCooldown = 0.f;
    }
}

void Enemy2::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{

}


void Enemy2::updatePhysics()
{
    velocity.y += gravity;
    if (velocity.y > velocityMaxY) {
        velocity.y = velocityMaxY;
    }

    velocity.y *= airResistance;    

    if (abs(velocity.y) < velocityMin) velocity.y = 0.f;

    position += velocity;
}

