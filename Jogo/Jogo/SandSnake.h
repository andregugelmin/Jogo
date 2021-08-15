#pragma once
#include "Enemy.h"
#include "Player.h"
#include"Projectile.h"

namespace Nightmare {
    class SandSnake :
        public Enemy
    {
    private:
        float attackCooldown;
        float attackCooldownMax;
        float attackRange;

    public:
        SandSnake(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* id = nullptr, Player* p = nullptr);
        ~SandSnake();

        void update() override;

        void initVariables();
        void shoot(sf::Vector2f targetPos);
        void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim) override;

    };
};
