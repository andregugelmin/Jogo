#include "Player.h"

Player::Player()
{
    initTextura();
    initSprite();
}

Player::~Player()
{
}
void Player::initTextura()
{
    if (!textura.loadFromFile("Texturas/Player1.jpg"))
    {
        cout << "Load Failed" << endl;
        system("pause");
    }
}

void Player::initSprite()
{
    sprite.setTexture(textura);
    sprite.setScale(0.5f, 0.5f);
    sprite.setPosition(sf::Vector2f(100.f, 100.f));
}


void Player::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        horizontalSpeed = 3.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        horizontalSpeed = -3.0f;
    }
    else {
        horizontalSpeed = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        verticalSpeed = -3.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        verticalSpeed = 3.0f;
    }
    else {
        verticalSpeed = 0;
    }
    sprite.move(sf::Vector2f(horizontalSpeed, verticalSpeed));
    sprite.move(sf::Vector2f(horizontalSpeed, verticalSpeed));
    position = sprite.getPosition();
}

sf::Vector2f Player::getPosition()
{
    return position;
}