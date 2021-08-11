#pragma once
#include "Collider.h"


class Projectile :
    public Collider
{
private:
    float speed;
    float lifeTime;
public:
    Projectile(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr, sf::Vector2f targetPos = sf::Vector2f(0.f, 0.f), float spd = 0.f, float ltime = 0.f);
    ~Projectile();

    void update() override;
        
    void updatePhysics() override;
    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim) override;

    sf::Vector2f setDirection(sf::Vector2f targetPos);
};



