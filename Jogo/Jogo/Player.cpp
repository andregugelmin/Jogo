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
    gravity = 1.5f;
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
    updateMovement();
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

        //for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++) //colidindo com o cenario
        //    for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
        //    {
        //        if (TileMap[i][j] == 'B')
        //        {
        //            if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
        //            if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
        //            if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
        //            if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
        //        }

        //        if (TileMap[i][j] == '0')
        //        {
        //            TileMap[i][j] = ' ';
        //        }

        //    }
    }    
}

void Player::shoot()
{
    if (level != nullptr) {
        level->spawnElement(new Projectile(position, "Textures/PlayerProjectile.png", "PlayerProjectile", sf::Vector2f(this->position.x + dir, this->position.y), 16, 10));        
        attackCooldown = 0.f;
    }
}


