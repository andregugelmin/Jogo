#include "Goblun.h"
#include "LevelManager.h"

namespace Nightmare {
    Goblun::Goblun(sf::Vector2f pos, const char* id, Player* p) :
        Enemy(pos, "Textures/Enemy1.png", id, p)
    {
        initVariables();
    }


    Goblun::~Goblun()
    {
    }

    void Goblun::initVariables()
    {
        acceleration = 0.4f;
        gravity = 2.f;
        drag = 0.9f;
        airResistance = 0.8f;
        velocityMaxX = 6.f;
        velocityMin = 0.2f;
        velocityMaxY = 15.f;
        numLife = 3;
    }

    void Goblun::update()
    {
        updateMovement();

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
                position.x = otherPos.x - dimensions.x * 0.9f;
            }
            else if ((delta.x < 0.0f && nextPos.x < 0.0f)) {
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

        if (otherId == "tile") {

            float deltax = otherPos.x - position.x;
            float deltay = otherPos.y - position.y;
            float intersectx = abs(deltax) - (otherDim.x / 2 + dimensions.x / 2);
            float intersecty = abs(deltay) - (otherDim.y / 2 + dimensions.y / 2);

            if (intersectx <= 0.0f && intersecty <= 0.0f) {
                if (intersectx > intersecty) {
                    if (deltax > 0.0f) {
                        position.x = otherPos.x - (otherDim.x / 2) - (dimensions.x / 2);
                        if (velocity.x > 0) {
                            velocity.x = 0;
                        }
                    }
                    else {
                        position.x = otherPos.x + (otherDim.x / 2) + (dimensions.x / 2);
                        if (velocity.x < 0) {
                            velocity.x = 0;
                        }
                    }

                }
                else {
                    if (deltay > 0.0f) {
                        position.y = otherPos.y - (otherDim.y / 2) - (dimensions.y / 2);
                        if (velocity.y > 0) {
                            onGround = true;
                            velocity.y = 0;
                        }

                    }
                    else {
                        position.y = otherPos.y + (otherDim.y / 2) + (dimensions.y / 2);
                        if (velocity.y < 0) {
                            velocity.y = 0;
                        }
                    }
                }
            }
        }
    }


    void Goblun::updateMovement()
    {
        if (player) {
            sf::Vector2f targetPos = player->getPosition();
            sf::Vector2f thisPos = getPosition();
            if (targetPos.x - thisPos.x < 500) {
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

        velocity.y += gravity;
    }
};

