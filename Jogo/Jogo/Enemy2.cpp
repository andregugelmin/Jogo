
#include "Enemy2.h"

Enemy2::Enemy2(sf::Vector2f pos, sf::Vector2f vel, const char* id, Player* p): Collider(pos, vel, "Textures/Enemy2.png", id), player(p)
{
}

Enemy2::~Enemy2()
{
}

void Enemy2::init(GraphicsManager& gm, CollisionManager& cm)
{
    gm.loadTexture(path);

    dimensions = gm.getSize(path);

    cm.addCollider(this);

    initVariables();
}

void Enemy2::update(GraphicsManager& gm)
{

    updateCollision(gm);
}

void Enemy2::draw(GraphicsManager& gm)
{
    gm.draw(path, position);
}

void Enemy2::initVariables()
{
    gravity = 2.f;
    velocityMaxY = 15.f;    
    airResistance = 0.8f;
    velocityMin = 0.5f;
}

void Enemy2::resetVelocityY()
{
    velocity.y = 0;
}

void Enemy2::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{

}

sf::Vector2f Enemy2::getPosition()
{
	return position;
}

void Enemy2::setTarget(Player* _player)
{
    player = _player;
}

void Enemy2::setPosition(const float x, const float y)
{
    position.x = x;
    position.y = y;
}

void Enemy2::updatePhysics()
{
    velocity.y += gravity;
    if (velocity.y > velocityMaxY) {
        velocity.y = velocityMaxY;
    }

    velocity.y *= airResistance;    

    if (abs(velocity.y) < velocityMin) velocity.y = 0.f;

    position += velocity;
}


void Enemy2::updateCollision(GraphicsManager& gm)
{
    if (getPosition().y + getDimensions().y > gm.getWindow()->getSize().y) {
        setPosition(getPosition().x,
            gm.getWindow()->getSize().y - getDimensions().y);
        resetVelocityY();
    }
}
