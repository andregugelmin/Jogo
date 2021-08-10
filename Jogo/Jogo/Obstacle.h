#pragma once
#include "Collider.h"
#include "Player.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"

using namespace sf;
class Obstacle :
    public Collider
{
protected:
    float dx, dy;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;
    static char TileMap[15][80];
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f dimensions;

    const char* path;

    LevelTest* level;

public:
    Obstacle(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr, sf::Vector2f targetPos = sf::Vector2f(0.f, 0.f));
    ~Obstacle();

    void update();

    void init(LevelTest* lvl, CollisionManager& cm);

    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim);
    void Collision(int dir);
};

//class Map1: public Obstacle
//{
//public:
//    Map1();
//private:
//    static char											lvl_1_Map[15][80];
//};
