#include "Enemy.h"

Enemy::Enemy(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile, const char* id, Player* p):
    Character(pos, vel, textureFile, id), player(p)
{
}

Enemy::~Enemy()
{
}

void Enemy::setTarget(Player* _player)
{
    player = _player;
}

