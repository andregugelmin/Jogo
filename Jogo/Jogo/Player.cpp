#include "Player.h"
#include "LevelManager.h"
#include <iostream>
#include "Obstacle.h"

namespace Nightmare {
    Player::Player(sf::Vector2f pos, const char* id) :
        Character(pos, "Textures/Player1.png", id), score(0)
    {
        initVariables();
    }

    Player::~Player()
    {
    }


    void Player::initVariables()
    {
        numLife = 3;
        dir = 1;
        onGround = false;
        gravity = 1.0f;
        acceleration = 0.8f;
        drag = 0.9f;
        airResistance = 0.98f;
        velocityMaxX = 5.f;
        velocityMaxY = 10.f;
        velocityMin = 0.2f;
        velocity.x = 0;
        velocity.y = 0;
        attackCooldown = 20.f;
        attackCooldownMax = 20.f;
        hitCooldown = 0;
        spawnPosition = getPosition();
    }

    void Player::update()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move(acceleration, 0);
            dir = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move(-acceleration, 0);
            dir = -1;
        }
        if (onGround) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                move(0.f, 20.f);
                onGround = false;
            }
        }

        if (hitCooldown > 0) {
            hitCooldown--;
        }

        velocity.y += gravity;

        if (velocity.x > 0) {
            
        }
        else if (velocity.x < 0) {
            
        }

        if (attackCooldown < attackCooldownMax) {
            attackCooldown += 0.5;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && attackCooldown >= attackCooldownMax) {
            shoot();
        }
    }

    void Player::draw()
    {
        if (level != nullptr) {
            level->getGraphicsManager()->draw(path, position);

            level->getGraphicsManager()->center(position);
        }
    }


    void Player::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
    {

        if (otherId == "enemy" || otherId == "enemy2" || otherId == "enemy3" || otherId == "enemyProjectile" || otherId == "damageObstacle") {
            if (hitCooldown <= 0) {
                hitCooldown = 10;
                numLife--;
                setPosition(spawnPosition.x, spawnPosition.y);
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

        if (otherId == "endLevel") {
            level->changeLevel();
        }
    }


    void Player::shoot()
    {
        if (level != nullptr) {
            level->spawnElement(new Projectile(position, "Textures/PlayerProjectile.png", "PlayerProjectile", sf::Vector2f(this->position.x + dir, this->position.y), 8, 50));
            attackCooldown = 0.f;
        }
    }

    void Player::increaseScore(const int s)
    {
        score += s;
    }

};
