#include <math.h>
#include "Projectile.h"
#include "LevelTest.h"
#include<iostream>

Projectile::Projectile(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile, const char* id, sf::Vector2f targetPos) : Collider(pos, vel, "Textures/Projectile.png", id), speed(3.f)
{
    velocity = setDirection(targetPos);
}

Projectile::~Projectile()
{
}

void Projectile::update()
{
}

void Projectile::updatePhysics()
{
    position += velocity * speed;
}

void Projectile::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{
    if (level != nullptr) {
        if (otherId == "player") {
            level->destroyElement(this);
        }
    }
}

sf::Vector2f Projectile::setDirection(sf::Vector2f targetPos)
{
    sf::Vector2f dir = targetPos - position;

    float m = sqrt(dir.x * dir.x + dir.y * dir.y);

    return sf::Vector2f(dir.x/m, dir.y/m);
}
