#include "Player.h"

Player::Player()
{
    initVariables();
    initTextura();
    initSprite();
    initAnimations();
}

Player::~Player()
{
}
void Player::initVariables()
{
    animState = IDLE;
    horizontalSpeed = 3.0f;
    verticalSpeed = 3.0f;
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

void Player::initAnimations()
{
    animationTimer.restart();
}


void Player::updateMovement()
{
    animState = IDLE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {        
        sprite.move(sf::Vector2f(horizontalSpeed, 0));
        animState = MOVING_RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {        
        sprite.move(sf::Vector2f(-horizontalSpeed, 0));
        animState = MOVING_LEFT;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {        
        sprite.move(sf::Vector2f(0, -verticalSpeed));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {        
        sprite.move(sf::Vector2f(0, verticalSpeed));
    }
    
    position = sprite.getPosition();
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
    else animationTimer.restart();
}

void Player::update()
{
    updateMovement();
    updateAnimations();
}

sf::Vector2f Player::getPosition()
{
    return position;
}