#include "Enemy.h"

namespace Nightmare {

    Enemy::Enemy(sf::Vector2f pos, const char* textureFile, const char* id, Player* p) :
        Character(pos, textureFile, id), player(p)
    {
    }

    Enemy::~Enemy()
    {
    }

    void Enemy::setTarget(Player* _player)
    {
        player = _player;
    }
};
