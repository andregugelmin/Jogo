#include "Character.h"
#include "LevelTest.h"
#include <iostream>
Character::Character(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile, const char* id):
	Collider(pos, vel, textureFile, id), gravity(0), drag(0), airResistance(0), velocityMaxY(0), velocityMin(0), acceleration(0), velocityMaxX(0), numLife(0), takeHit(false)
{
}

Character::~Character()
{
}

void Character::move(const float x, const float y)
{
    velocity.x += x;

    velocity.y -= y;
}

void Character::updatePhysics()
{

    if (velocity.y > velocityMaxY) velocity.y = velocityMaxY;

    if (abs(velocity.x) > velocityMaxX) {
        velocity.x = velocityMaxX * ((velocity.x < 0.f) ? -1.f : 1.f);
    }

    velocity.x *= drag;
    velocity.y *= airResistance;

    if (abs(velocity.x) < velocityMin) velocity.x = 0.f;
    if (abs(velocity.y) < velocityMin) velocity.y = 0.f;

    std::cout << velocity.y << std::endl;

    position += velocity;
}

void Character::setDead()
{
    if (level != nullptr) {
        {
            level->destroyElement(this);
        }
    }
}


void Character::resetVelocityY()
{
    velocity.y = 0.f;
}

void Character::updateCollision(GraphicsManager* gm)
{
    if (gm != nullptr) {
        if (getPosition().y + getDimensions().y > gm->getWindow()->getSize().y) {
            setPosition(getPosition().x,
                gm->getWindow()->getSize().y - getDimensions().y);
            resetVelocityY();
        }
    }
}