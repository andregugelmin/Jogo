#include "Player.h"

Player::Player(sf::Vector2f pos):
    Entity(pos, sf::Vector2f(0.f,0.f), "Textures/Player1.png")
{
    initVariables();   
}

Player::~Player()
{
}

void Player::init(GraphicsManager& gm)
{
    gm.loadTexture(path);

    dimensions = gm.getSize(path);
}

void Player::draw(GraphicsManager& gm)
{
    gm.draw(path, position);

    gm.center(position);
}

void Player::initVariables()
{
    onGround = false;
    horizontalSpeed = 1.25f;
    gravity = 2.f;
    acceleration = 1.f;
    drag = 0.8f;
    airResistance = 0.98f;
    velocityMaxX = 5.f;
    velocityMaxY = 15.f;
    velocityMin = 1.f;
    velocity.x = 0;
    velocity.y = 0;
}


void Player::move(const float x, const float y)
{
    velocity.x += x * acceleration;

    if (abs(velocity.x) > velocityMaxX) {
        velocity.x = velocityMaxX * ((velocity.x < 0.f) ? -1.f : 1.f);
    }

    velocity.y -= y;

    position += velocity;
}

void Player::resetVelocityY()
{
    velocity.y = 0.f;
}

void Player::updatePhysics()
{
    velocity.y += 1.0 * gravity;
    if (velocity.y > velocityMaxY) {
        velocity.y = velocityMaxY;
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
        move(horizontalSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-horizontalSpeed, 0);
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
        resetVelocityY();
        onGround = true;
    }
}

void Player::update(GraphicsManager& gm)
{    
    updateMovement();
    updatePhysics();
    updateCollision(gm);

    std::cout << velocity.x << "," << velocity.y << endl;
}

sf::Vector2f Player::getPosition()
{
    return position;
}

sf::Vector2f Player::getMidPosition()
{
    sf::Vector2f midPos = position;
    midPos.x /= 2;
    midPos.y /= 2;
    return midPos;
}


void Player::setPosition(const float x, const float y)
{
    position.x = x;
    position.y = y;
}


