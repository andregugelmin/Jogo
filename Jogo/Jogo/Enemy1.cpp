#include "Enemy1.h"

Enemy1::Enemy1(sf::Vector2f pos, sf::Vector2f vel, const char* id, Player* p):
    Collider(pos, vel, "Textures/Enemy1.png", id), player(p)
{
 
}


Enemy1::~Enemy1()
{
    //if(projetil!=NULL) delete projetil;
}

void Enemy1::init(GraphicsManager& gm, CollisionManager& cm)
{
gm.loadTexture(path);

dimensions = gm.getSize(path);

cm.addCollider(this);

initVariables();
}

void Enemy1::draw(GraphicsManager& gm)
{
    gm.draw(path, position);

}

void Enemy1::initVariables()
{
    acceleration = 0.75f;
    gravity = 2.f;
    drag = 0.95f;
    airResistance = 0.8f;
    velocityMaxX = 20.f;
    velocityMaxY = 15.f;
    velocityMin = 0.5f;
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


//Projetil* Enemy1::getProjetil()
//{
//    return projetil;
//}

void Enemy1::setPosition(const float x, const float y)
{
    position.x = x;
    position.y = y;
}


void Enemy1::move(const float x, const float y)
{
    velocity.x += x;

    velocity.y -= y;
}

void Enemy1::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{
    if (otherId == "enemy") {
        sf::Vector2f delta;
        sf::Vector2f nextPos;

        nextPos = position + velocity;

        delta = otherPos - position;        
       
        if ((delta.x > 0.0f && nextPos.x > 0.0f)) {
            velocity.x = 0;
            position.x = otherPos.x - dimensions.x*0.9f;
        }
        else if((delta.x < 0.0f && nextPos.x < 0.0f)) {
            velocity.x = 0;
            position.x = otherPos.x + dimensions.x * 0.9f;
        }
                
    }
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
    velocity.y += gravity;
    if (velocity.y > velocityMaxY) {
        velocity.y = velocityMaxY;
    }

    if (abs(velocity.x) > velocityMaxX) {
        velocity.x = velocityMaxX * ((velocity.x < 0.f) ? -1.f : 1.f);
    }

    velocity.y *= airResistance;
    velocity.x *= drag;


    if (abs(velocity.x) < velocityMin) velocity.x = 0.f;
    if (abs(velocity.y) < velocityMin) velocity.y = 0.f;

    position+=velocity;
}

void Enemy1::updateMovement()
{
    if (player) {
        sf::Vector2f targetPos = player->getPosition();
        sf::Vector2f thisPos = getPosition();

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
    updateCollision(gm);
    //projetil->update(gm);
}
