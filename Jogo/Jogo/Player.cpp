#include "Player.h"
#include "LevelTest.h"
#include <iostream>

Player::Player(sf::Vector2f pos, const char* id):
    Collider(pos, sf::Vector2f(0.f,0.f), "Textures/Player1.png", id)
{
    initVariables();
}

Player::~Player()
{
}


void Player::initVariables()
{
    onGround = false;
    gravity = 1.5f;
    acceleration = 1.25f;
    drag = 0.9f;
    airResistance = 0.98f;
    velocityMaxX = 15.f;
    velocityMaxY = 15.f;
    velocityMin = 1.f;
    velocity.x = 0;
    velocity.y = 0;
}

void Player::update()
{
    updateMovement();
    if (level != nullptr) {
        updateCollision(level->getGraphicsManager());
    }
}

void Player::draw()
{
    if (level != nullptr) {
        level->getGraphicsManager()->draw(path, position);

        level->getGraphicsManager()->center(position);

    }
}

void Player::move(const float x, const float y)
{
    velocity.x += x;

    velocity.y -= y;

}

void Player::resetVelocityY()
{
    velocity.y = 0.f;
}

void Player::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{
    
}

void Player::updatePhysics()
{
    velocity.y += 1.0 * gravity;
    if (velocity.y > velocityMaxY) velocity.y = velocityMaxY;

    if (abs(velocity.x) > velocityMaxX) {
        velocity.x = velocityMaxX * ((velocity.x < 0.f) ? -1.f : 1.f);
    }

    velocity.x *= drag;
    velocity.y *= airResistance;

    if (abs(velocity.x) < velocityMin) velocity.x = 0.f;
    if (abs(velocity.y) < velocityMin) velocity.y = 0.f;
    

    position += velocity;
}

void Player::updateMovement()
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


