#include "Player.h"
#include "LevelTest.h"
#include <iostream>
#include "Obstacle.h"


Player::Player(sf::Vector2f pos, const char* id):
    Character(pos, sf::Vector2f(0.f,0.f), "Textures/Player1.png", id)
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
    gravity = 1.2f;
    acceleration = 1.25f;
    drag = 0.9f;
    airResistance = 0.98f;
    velocityMaxX = 15.f;
    velocityMaxY = 15.f;
    velocityMin = 1.f;
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
            move(0.f, 15.f);
            onGround = false;
        }
    }

    velocity.y += gravity;

    if (level != nullptr) {
        updateCollision(level->getGraphicsManager());
    }
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

        sf::Vector2f delta;

        delta = otherPos - position;        
        if (position.y + dimensions.y / 2 > otherPos.y + otherDim.y/2) {
            position.y = otherPos.y;
            onGround = true;
            if (velocity.y > 0) resetVelocityY();
        }           
        

        /*
        if ((delta.x > 0.0f && nextPos.x > 0.0f)) {
            velocity.x = 0;
            position.x = otherPos.x - dimensions.x;
        }
        else if ((delta.x < 0.0f && nextPos.x < 0.0f)) {
            velocity.x = 0;
            position.x = otherPos.x + dimensions.x;
        }
        */
    }
}


void Player::updateCollision(GraphicsManager* gm)
{
    if (gm != nullptr) {
        if (getPosition().y + getDimensions().y > gm->getWindow()->getSize().y) {
            setPosition(getPosition().x,
                gm->getWindow()->getSize().y - getDimensions().y);
            if (velocity.y > 0) resetVelocityY();
            onGround = true;
        }             
    }    
}

void Player::shoot()
{
    if (level != nullptr) {
        level->spawnElement(new Projectile(position, "Textures/PlayerProjectile.png", "PlayerProjectile", sf::Vector2f(this->position.x + dir, this->position.y), 16, 10));        
        attackCooldown = 0.f;
    }
}


