#pragma once
#include "Entity.h"
#include "Player.h"
//#include "Projetil.h"

class Game;

//enum ENEMY_ANIMATION_STATES { EIDLE = 0, EMOVING_LEFT, EMOVING_RIGHT };

class Enemy1 :
    public Entity
{
private:

    float horizontalSpeed;
    float gravity;
    float drag;
    float airResistance;
    float velocityMaxY;
    float velocityMin;
    float acceleration;
    float velocityMaxX;

    Player* player;
    //Projetil* projetil;

   

public:
    Enemy1(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), Player* p = nullptr);
    ~Enemy1();

    void init(GraphicsManager& gm);
    void update(GraphicsManager& gm);
    void draw(GraphicsManager& gm);

    void initVariables();

    void resetVelocityY();
    void followPlayer();
    void move(const float x, const float y);
    //void shoot(const int d);

    //Getters
    sf::Vector2f getPosition();
    sf::Vector2f getMidPosition();
    //Projetil* getProjetil();

    //Setters
    void setTarget(Player* _player);
    void setPosition(const float x, const float y);

    //Updates    
    void updatePhysics();
    void updateMovement();
    void updateCollision(GraphicsManager& gm);
 
};