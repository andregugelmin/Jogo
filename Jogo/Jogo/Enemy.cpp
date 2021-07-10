#include "Enemy.h"

Enemy::Enemy()
{
    initTextura();
    initSprite();
}


Enemy::~Enemy()
{
}


void Enemy::initTextura()
{
    if (!textura.loadFromFile("Texturas/Enemy.jpg"))
    {
        cout << "Load Failed" << endl;
        system("pause");
    }
}

void Enemy::initSprite()
{
    sprite.setTexture(textura);
    sprite.setScale(0.5f, 0.5f);
    sprite.setPosition(sf::Vector2f(200.f, 200.f));
}

void Enemy::setTarget(Player* _player)
{
	player = _player;
}

void Enemy::atualiza()
{
	targetPos = player->getPosition();
	thisPos = sprite.getPosition();
    sprite.sf::Transformable::move((targetPos.x - thisPos.x) / 50, (targetPos.y - thisPos.y) / 50);

}
