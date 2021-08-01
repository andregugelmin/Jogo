#include "Entity.h"

Entity::Entity(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile): position(pos), velocity(vel), path(textureFile)
{
}

Entity::~Entity()
{
}

void Entity::init(GraphicsManager& gm)
{
	gm.loadTexture(path);

	gm.getWindow()->setKeyRepeatEnabled(false);
}

void Entity::update(GraphicsManager& gm)
{
	
}

void Entity::draw(GraphicsManager& gm)
{
	gm.draw(path, position);
}

const sf::Vector2f Entity::getPosition() const
{
	return position;
}

const sf::Vector2f Entity::getDimensions() const
{
	return dimensions;
}
