#include "Player.h"

Player::Player()
{
    initVariables();
    initTextura();
    initSprite();
    initPhysics();
    initAnimations();
}

Player::~Player()
{
}


void Player::initVariables()
{
    animState = IDLE;
    onGround = false;
    horizontalSpeed = 3.f;
}

void Player::initTextura()
{
    if (!textura.loadFromFile("Texturas/Player_spritesheet.png"))
    {
        cout << "Load Failed" << endl;
        system("pause");
    }
}

void Player::initSprite()
{
    sprite.setTexture(textura);
    currentFrame = sf::IntRect(0, 3, 100, 59);
    sprite.setTextureRect(currentFrame);
    sprite.setPosition(sf::Vector2f(100.f, 100.f));
}

void Player::initPhysics()
{
    gravity = 2.f;
    acceleration = 1.f;
    drag = 0.8f;
    airResistance = 0.8f;
    velocityMaxX = 5.f;
    velocityMaxY = 15.f;
    velocityMin = 1.f;
    velocity.x = 0;
    velocity.y = 0;
}

void Player::initAnimations()
{
    animationTimer.restart();
}



void Player::move(const float x, const float y)
{
    velocity.x += x * acceleration;

    if (abs(velocity.x) > velocityMaxX) {
        velocity.x = velocityMaxX * ((velocity.x < 0.f) ? -1.f : 1.f);
    }

    velocity.y -= y;
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

    sprite.move(velocity);
}

void Player::updateMovement()
{
    
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        move(horizontalSpeed, 0);
        if (onGround) animState = MOVING_RIGHT;
        sprite.setScale(1.0f, 1.0f);
        sprite.setOrigin(0.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        move(-horizontalSpeed, 0);
        if (onGround) animState = MOVING_LEFT;
        sprite.setScale(-1.0f, 1.0f);
        sprite.setOrigin(sprite.getGlobalBounds().width, 0.f);
    }

    if (onGround) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            move(0.f, 50.f);
            onGround = false;
            currentFrame.left = 0;
            animationTimer.restart();
            animState = JUMPING;
            
        }
    }
    
}

void Player::updateAnimations()
{     

    if (animState == IDLE) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
           
            currentFrame.top = 177.f;
            currentFrame.left += 100.f;
            if (currentFrame.left >= 400.f) currentFrame.left = 0;            

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else if (animState == MOVING_RIGHT) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
            currentFrame.top = 118.f;
            currentFrame.left += 100.f;
            if (currentFrame.left >= 600.f) currentFrame.left = 0;

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
            
        }
        
    }
    else if (animState == MOVING_LEFT) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
            currentFrame.top = 118.f;
            currentFrame.left += 100.f;
            if (currentFrame.left >= 600.f) currentFrame.left = 0;

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
            
        }
        
    }    
    else if (animState == JUMPING) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.1f) {
            currentFrame.top = 59.f;
            currentFrame.left += 100.f;
            if (currentFrame.left >= 100.f) currentFrame.left = 100.f;

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);

        }        
    }
    else animationTimer.restart();

    if (onGround) {
        animState = IDLE;
    }    
    
}

void Player::updateCollision()
{
    if (getPosition().y + getGlobalBounds().height > window->getSize().y) {
        setPosition(getPosition().x,
            window->getSize().y - getGlobalBounds().height);
        resetVelocityY();
        onGround = true;
    }
}

void Player::update()
{    
    updateMovement();
    updatePhysics();
    updateCollision();
    updateAnimations();    
}

sf::Vector2f Player::getPosition()
{
    return sprite.getPosition();
}

sf::Vector2f Player::getMidPosition()
{
    sf::Vector2f midPos = getPosition();
    midPos.x += getGlobalBounds().width / 2;
    midPos.y += getGlobalBounds().height / 2;
    return midPos;
}

const sf::FloatRect Player::getGlobalBounds() const
{
    return sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y)
{
    sprite.setPosition(x, y);
}


