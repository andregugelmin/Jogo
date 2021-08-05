#include "Collider.h"
#include "Player.h"

class Enemy2 :
    public Collider
{
private:
    float gravity;
    float airResistance;
    float velocityMaxY;
    float velocityMin;

    Player* player;

public:
    Enemy2(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* id = nullptr, Player* p = nullptr);
    ~Enemy2();

    void init(GraphicsManager& gm, CollisionManager& cm);
    void update(GraphicsManager& gm);
    void draw(GraphicsManager& gm);

    void initVariables();
    void resetVelocityY();

    void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim);

    sf::Vector2f getPosition();

    void setTarget(Player* _player);
    void setPosition(const float x, const float y);
  
    void updatePhysics();
    void updateCollision(GraphicsManager& gm);
};
