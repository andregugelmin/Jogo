#include <math.h>
#include "Projectile.h"
#include "LevelManager.h"
#include<iostream>

namespace Nightmare {

    Projectile::Projectile(sf::Vector2f pos, const char* textureFile, const char* id, sf::Vector2f targetPos, float spd, float ltime) :
        Collider(pos, textureFile, id), speed(spd), lifeTime(ltime)
    {
        velocity = setDirection(targetPos);
    }

    Projectile::~Projectile()
    {
    }

    void Projectile::update()
    {
        lifeTime -= 1.f;
        if (level && lifeTime <= 0.f) {
            level->destroyElement(this);
        }
    }

    void Projectile::updatePhysics()
    {
        position += velocity * speed;
    }

    void Projectile::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
    {
        if (level != nullptr) {
            if (this->ID == "bullet" && otherId == "player") {
                level->destroyElement(this);
            }
            else if (this->ID == "PlayerProjectile" && (otherId == "enemy" || otherId == "enemy2" || otherId == "enemy3")) {
                level->destroyElement(this);

            }
        }
    }

    sf::Vector2f Projectile::setDirection(sf::Vector2f targetPos)
    {
        sf::Vector2f dir = targetPos - position;

        float m = sqrt(dir.x * dir.x + dir.y * dir.y);

        return sf::Vector2f(dir.x / m, dir.y / m);
    }
};
