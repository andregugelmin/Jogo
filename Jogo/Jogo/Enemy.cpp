#include "Enemy.h"



Enemy::Enemy(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile, const char* id, Player* p):
    Collider(pos, vel, textureFile, id), player(p), gravity(0), drag(0), airResistance(0), velocityMaxY(0), velocityMin(0), acceleration(0), velocityMaxX(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::resetVelocityY()
{
    velocity.y = 0.f;
}

void Enemy::setTarget(Player* _player)
{
    player = _player;
}

void Enemy::updateCollision(GraphicsManager* gm)
{
    if (gm != nullptr) {
        if (getPosition().y + getDimensions().y > gm->getWindow()->getSize().y) {
            setPosition(getPosition().x,
                gm->getWindow()->getSize().y - getDimensions().y);
            resetVelocityY();
        }
    }
}
