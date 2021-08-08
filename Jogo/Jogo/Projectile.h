#pragma once
#include "Collider.h"


class Projectile :
    public Collider
{
private:
    float speed;

public:
    Projectile(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr, sf::Vector2f targetPos = sf::Vector2f(0.f, 0.f));
    ~Projectile();

    void update();
        
    void updatePhysics();
    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim);

    sf::Vector2f setDirection(sf::Vector2f targetPos);
};



