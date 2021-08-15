#include "Player.h"
#include "LevelTest.h"
#include <iostream>
#include "Obstacle.h"


Player::Player(sf::Vector2f pos, const char* id):
    Character(pos, "Textures/Player1.png", id)
{
    initVariables();
}

Player::~Player()
{
}


void Player::initVariables()
{
    dir = 1;
    onGround = false;
    gravity = 1.5f;
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
}

void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(acceleration, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-acceleration, 0);
    }
    if (onGround) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            move(0.f, 20.f);
            onGround = false;
        }
    }

    velocity.y += gravity;

    if (velocity.x > 0) {
        dir = 1;
    }
    else if (velocity.x < 0) {
        dir = -1;
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
                    position.y = otherPos.y + (otherDim.y / 2) + (dimensions.y / 2) ;                    
                    if (velocity.y < 0) {
                        velocity.y = 0;
                    }
                }
            }
        }
    }
}


void Player::shoot()
{
    if (level != nullptr) {
        level->spawnElement(new Projectile(position, "Textures/PlayerProjectile.png", "PlayerProjectile", sf::Vector2f(this->position.x + dir, this->position.y), 8, 50));        
        attackCooldown = 0.f;
    }
}


