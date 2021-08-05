#include "Player.h"

Player::Player(sf::Vector2f pos, const char* id):
    Collider(pos, sf::Vector2f(0.f,0.f), "Textures/Player1.png", id)
{  
}

Player::~Player()
{
}

void Player::init(GraphicsManager& gm, CollisionManager& cm)
{
    gm.loadTexture(path);

    dimensions = gm.getSize(path);

    cm.addCollider(this);

    initVariables();
}

void Player::draw(GraphicsManager& gm)
{
    gm.draw(path, position);

    gm.center(position);
}

void Player::initVariables()
{
    onGround = false;
    gravity = 2.f;
    acceleration = 1.25f;
    drag = 0.9f;
    airResistance = 0.98f;
    velocityMaxX = 15.f;
    velocityMaxY = 15.f;
    velocityMin = 1.f;
    velocity.x = 0;
    velocity.y = 0;
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

void Player::updateCollision(GraphicsManager& gm)
{
    if (getPosition().y + getDimensions().y > gm.getWindow()->getSize().y) {
        setPosition(getPosition().x,
            gm.getWindow()->getSize().y - getDimensions().y);
        if(velocity.y > 0) resetVelocityY();
        onGround = true;
    }
}

void Player::update(GraphicsManager& gm)
{    
    updateMovement();
    updateCollision(gm);
}

sf::Vector2f Player::getPosition()
{
    return position;
}


void Player::setPosition(const float x, const float y)
{
    position.x = x;
    position.y = y;
}


