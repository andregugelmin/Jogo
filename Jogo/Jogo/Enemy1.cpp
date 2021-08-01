#include "Enemy1.h"

Enemy1::Enemy1(sf::Vector2f pos, sf::Vector2f vel, Player* p):
    Entity(pos, vel, "Textures/Enemy1.png"), player(p)
{
 
}


Enemy1::~Enemy1()
{
    //if(projetil!=NULL) delete projetil;
}

void Enemy1::init(GraphicsManager& gm)
{
    gm.loadTexture(path);

    dimensions = gm.getSize(path);

    initVariables();
}

void Enemy1::draw(GraphicsManager& gm)
{
    gm.draw(path, position);

}

void Enemy1::initVariables()
{
    horizontalSpeed = 0.5f;
    acceleration = 1.f;
    gravity = 2.f;
    drag = 0.85f;
    airResistance = 0.8f;
    velocityMaxX = 5.f;
    velocityMaxY = 15.f;
    velocityMin = 1.f;
}


void Enemy1::setTarget(Player* _player)
{
	player = _player;
}

void Enemy1::resetVelocityY()
{
    velocity.y = 0.f;
}

sf::Vector2f Enemy1::getPosition()
{
    return position;
}

sf::Vector2f Enemy1::getMidPosition()
{
    sf::Vector2f midPos = position;
    midPos.x /= 2;
    midPos.y /= 2;
    return midPos;
}


//Projetil* Enemy1::getProjetil()
//{
//    return projetil;
//}

void Enemy1::setPosition(const float x, const float y)
{
    position.x = x;
    position.y = y;
}

void Enemy1::followPlayer()
{
    if (player) {
        sf::Vector2f targetPos = player->getMidPosition();
        sf::Vector2f thisPos = getMidPosition();

        if (targetPos.y - thisPos.y <= 5 && targetPos.y - thisPos.y > -100) {

            if ((targetPos.x - thisPos.x) > 100.f) {
                move(horizontalSpeed, 0);

            }
            else if ((targetPos.x - thisPos.x) < -100.f) {
                move(-horizontalSpeed, 0);
            }
        }
    }
}

void Enemy1::move(const float x, const float y)
{
    velocity.x += x * acceleration;

    if (abs(velocity.x) > velocityMaxX) {
        velocity.x = velocityMaxX * ((velocity.x < 0.f) ? -1.f : 1.f);
    }

    velocity.y -= y;
}

/*
 void Enemy1::shoot(const int d)
{
    float posx = 0, posy = 0;
    posx = getPosition().x;
    posy = getPosition().y;
    projetil = new Projetil(position, sf::Vector2f(50.f, 0.f));
}
*/


void Enemy1::updatePhysics()
{
    velocity.y += 1.0 * gravity;
    if (velocity.y > velocityMaxY) {
        velocity.y = velocityMaxY;
    }

    velocity.y *= airResistance;
    velocity.x *= drag;

    if (abs(velocity.y) < velocityMin) velocity.y = 0.f;

    position+=velocity;
}

void Enemy1::updateMovement()
{
    followPlayer();
}

void Enemy1::updateCollision(GraphicsManager& gm)
{
    
    if (getPosition().y + getDimensions().y > gm.getWindow()->getSize().y) {
        setPosition(getPosition().x,
            gm.getWindow()->getSize().y - getDimensions().y);
        resetVelocityY();
    }
}

void Enemy1::update(GraphicsManager& gm)
{
    updateMovement();
    updatePhysics();
    updateCollision(gm);
    //projetil->update(gm);
}
