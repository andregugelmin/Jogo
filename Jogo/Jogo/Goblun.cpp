#include "Goblun.h"
#include "LevelTest.h"

Goblun::Goblun(sf::Vector2f pos, sf::Vector2f vel, const char* id, Player* p):
    Enemy(pos, vel, "Textures/Enemy1.png", id, p)
{
    initVariables();
}


Goblun::~Goblun()
{
}

void Goblun::initVariables()
{
    acceleration = 0.75f;
    gravity = 2.f;
    drag = 0.95f;
    airResistance = 0.8f;
    velocityMaxX = 20.f;
    velocityMin = 0.5f;
    velocityMaxY = 15.f;
    numLife = 3;
}

void Goblun::update()
{
    updateMovement();
    if (level != nullptr) {
        updateCollision(level->getGraphicsManager());
    }

    if (hitCooldown > 0) {
        hitCooldown--;
    }

}

void Goblun::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{
    if (otherId == "enemy") {
        sf::Vector2f delta;
        sf::Vector2f nextPos;

        nextPos = position + velocity;

        delta = otherPos - position;        
       
        if ((delta.x > 0.0f && nextPos.x > 0.0f)) {
            velocity.x = 0;
            position.x = otherPos.x - dimensions.x*0.9f;
        }
        else if((delta.x < 0.0f && nextPos.x < 0.0f)) {
            velocity.x = 0;
            position.x = otherPos.x + dimensions.x * 0.9f;
        }                
    }

    if (otherId == "PlayerProjectile" && hitCooldown <= 0) {
        hitCooldown = 10;
        numLife--;
        if (numLife <= 0) {
            setDead();
        }
    }
}


void Goblun::updateMovement()
{
    if (player) {
        sf::Vector2f targetPos = player->getPosition();
        sf::Vector2f thisPos = getPosition();

        if (targetPos.y - thisPos.y <= 5.f && targetPos.y - thisPos.y > -200.f) {

            if ((targetPos.x - thisPos.x) > 10.f) {
                move(acceleration, 0);

            }
            else if ((targetPos.x - thisPos.x) < -10.f) {
                move(-acceleration, 0);
            }
        }
    }
}


