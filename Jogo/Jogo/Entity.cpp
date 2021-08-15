#include "Entity.h"
#include "LevelManager.h"

namespace Nightmare {
    Entity::Entity(sf::Vector2f pos, const char* textureFile) : position(pos), velocity(sf::Vector2f(0.0f, 0.0f)), scale(sf::Vector2f(1.0f, 1.0f)), path(textureFile), level(nullptr)
    {
    }

    Entity::~Entity()
    {
    }

    void Entity::init(LevelManager* lvl, CollisionManager& cm)
    {
        if (lvl != nullptr) {
            setLevel(lvl);

            level->getGraphicsManager()->loadTexture(path);
            dimensions = level->getGraphicsManager()->getSize(path);
        }

    }

    void Entity::updatePhysics()
    {
    }

    void Entity::setPosition(const float x, const float y)
    {
        position.x = x;
        position.y = y;
    }

    void Entity::setVelocity(const float x, const float y)
    {
        velocity.x = x;
        velocity.y = y;
    }

    const sf::Vector2f Entity::getPosition() const
    {
        return position;
    }

    const sf::Vector2f Entity::getDimensions() const
    {
        return dimensions;
    }

    const sf::Vector2f Entity::getVelocity() const
    {
        return velocity;
    }

    void Entity::setLevel(LevelManager* lvl)
    {
        level = lvl;
    }

    void Entity::setScale(sf::Vector2f s)
    {
        scale = s;
    }
};
