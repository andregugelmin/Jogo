#include "GiantBat.h"
#include "LevelManager.h"

namespace Nightmare {
    GiantBat::GiantBat(sf::Vector2f pos, const char* id, Player* p) :
        Enemy(pos, "Textures/Enemy3.png", id, p)
    {
        initVariables();
    }

    GiantBat::~GiantBat()
    {
    }

    void GiantBat::initVariables()
    {
        acceleration = 1.25f;
        drag = 0.8f;
        velocityMaxX = 20.f;
        velocityMin = 0.5f;
        shoots = 0;
        attackCooldown = 50.f;
        attackCooldownMax = 100.f;
        attackRange = 500.f;
        numLife = 20;
    }

    void GiantBat::update()
    {


        if (attackCooldown < attackCooldownMax) {
            attackCooldown += 0.5;
        }

        if (player) {
            sf::Vector2f targetPos = player->getPosition();
            sf::Vector2f thisPos = getPosition();
            sf::Vector2f distance = (targetPos - thisPos);
            float range = sqrt((distance.x * distance.x) + (distance.y * distance.y));

            if (range <= attackRange)  shoot(targetPos);

            followPlayer(range);
        }
        if (hitCooldown > 0) {
            hitCooldown--;
        }
    }


    void GiantBat::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
    {
        if (otherId == "PlayerProjectile" && hitCooldown <= 0) {
            hitCooldown = 10;
            numLife--;
            if (numLife <= 0) {
                setDead();
            }
        }
    }

    void GiantBat::followPlayer(float range)
    {
        sf::Vector2f targetPos = player->getPosition();
        sf::Vector2f thisPos = getPosition();

        if (range > 400.f && range < 600) {
            if (targetPos.x - thisPos.x > 0) move(acceleration, 0);

            else if (targetPos.x - thisPos.x < 0) move(-acceleration, 0);
        }
    }

    void GiantBat::shoot(sf::Vector2f targetPos)
    {
        if (level != nullptr && attackCooldown >= attackCooldownMax) {
            level->spawnElement(new Projectile(position, "Textures/Projectile.png", "bullet", targetPos, 8.f, 150.f));
            attackCooldown = 0.f;
            shoots++;
            if (shoots < 3) {
                attackCooldownMax = 5.f;
            }
            else {
                shoots = 0;;
                attackCooldownMax = 100.f;
            }
        }
    }
};