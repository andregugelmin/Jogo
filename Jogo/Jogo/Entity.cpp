#include "Entity.h"
#include "LevelTest.h"

Entity::Entity(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile): position(pos), velocity(vel), path(textureFile), level(nullptr)
{
}

Entity::~Entity()
{
}

void Entity::init(LevelTest* lvl, CollisionManager& cm)
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

const sf::Vector2f Entity::getPosition() const
{
	return position;
}

const sf::Vector2f Entity::getDimensions() const
{
	return dimensions;
}

void Entity::setLevel(LevelTest* lvl)
{
	level = lvl;
}

