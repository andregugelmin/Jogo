#include "Ghost.h"

Ghost::Ghost()
{
    initVariables();
    initTextura();
    initSprite();
    initPhysics();
    initAnimations();
}


Ghost::~Ghost()
{
}


void Ghost::initVariables()
{
    animState = IDLE;
}

void Ghost::initTextura()
{
    if (!textura.loadFromFile("Texturas/Ghost_spritesheet.png"))
    {
        cout << "Load Failed" << endl;
        system("pause");
    }
}

void Ghost::initSprite()
{
    sprite.setTexture(textura);
    currentFrame = sf::IntRect(0, 0, 37, 65);
    sprite.setTextureRect(currentFrame);
    sprite.setPosition(sf::Vector2f(100.f, 100.f));
}

void Ghost::initPhysics()
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

void Ghost::initAnimations()
{
    animationTimer.restart();
}

void Ghost::setTarget(Player* _player)
{
	player = _player;
}

void Ghost::resetVelocityY()
{
    velocity.y = 0.f;
}

sf::Vector2f Ghost::getPosition()
{
    return sprite.getPosition();
}

sf::Vector2f Ghost::getMidPosition()
{
    sf::Vector2f midPos = getPosition();
    midPos.x += getGlobalBounds().width / 2;
    midPos.y += getGlobalBounds().height / 2;
    return midPos;
}

const sf::FloatRect Ghost::getGlobalBounds() const
{
    return sprite.getGlobalBounds();
}

void Ghost::setPosition(const float x, const float y)
{
    sprite.setPosition(x, y);
}

void Ghost::followPlayer()
{
	targetPos = player->getMidPosition();
	thisPos = getMidPosition();
    
    if (targetPos.y - thisPos.y<= 5 && targetPos.y - thisPos.y > -100) {

        if ((targetPos.x - thisPos.x) > 200.f) {
            move(horizontalSpeed, 0);
            animState = MOVING_RIGHT;

        }
        else if ((targetPos.x - thisPos.x) < -200.f) {
            move(-horizontalSpeed, 0);
            animState = MOVING_LEFT;
        }
        else {
            animState = ATACKING;
        }
    }
    else {
        animState = IDLE;
    }
    cout << targetPos.y - thisPos.y << endl;

}

void Ghost::move(const float x, const float y)
{
    velocity.x += x * acceleration;

    if (abs(velocity.x) > velocityMaxX) {
        velocity.x = velocityMaxX * ((velocity.x < 0.f) ? -1.f : 1.f);
    }

    velocity.y -= y;
}

void Ghost::updatePhysics()
{
    velocity.y += 1.0 * gravity;
    if (velocity.y > velocityMaxY) {
        velocity.y = velocityMaxY;
    }

    velocity.y *= airResistance;
    velocity.x *= drag;

    if (abs(velocity.y) < velocityMin) velocity.y = 0.f;

    sprite.move(velocity);
}

void Ghost::updateMovement()
{
    followPlayer();
}

void Ghost::updateAnimations()
{
    if (animState == IDLE) 
    {    
        animationTimer.restart();
        currentFrame.left = 0.f;        
        sprite.setTextureRect(currentFrame);        
    }
    else if (animState == MOVING_RIGHT) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {            
            currentFrame.left += 37.f;
            if (currentFrame.left >= 111.f) currentFrame.left = 0;

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);            
        }
        sprite.setScale(1.0f, 1.0f);
        sprite.setOrigin(0.f, 0.f);
    }
    else if (animState == MOVING_LEFT) {
        if (animationTimer.getElapsedTime().asSeconds() >= 0.2f) {            
            currentFrame.left += 37.f;
            if (currentFrame.left >= 111.f) currentFrame.left = 0;

            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
        sprite.setScale(-1.0f, 1.0f);
        sprite.setOrigin(sprite.getGlobalBounds().width, 0.f);
    }
    else animationTimer.restart();
}

void Ghost::updateCollision()
{
    if (getPosition().y + getGlobalBounds().height > window->getSize().y) {
        setPosition(getPosition().x,
            window->getSize().y - getGlobalBounds().height);
        resetVelocityY();
    }
}

void Ghost::update()
{
    updateMovement();
    updatePhysics();
    updateCollision();
    updateAnimations();
}
