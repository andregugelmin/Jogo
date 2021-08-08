#include "Collider.h"
#include "LevelTest.h"
#include <iostream>

Collider::Collider(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile, const char* id): Entity(pos, vel, textureFile), ID(id)
{
}

Collider::~Collider()
{
}

void Collider::init(LevelTest* lvl, CollisionManager& cm)
{
	if (lvl != nullptr) {
		setLevel(lvl);

		level->getGraphicsManager()->loadTexture(path);
		dimensions = level->getGraphicsManager()->getSize(path);
	}

	cm.addCollider(this);
}

const char* Collider::getID() const
{
	return ID;
}

void Collider::setId(const char* id)
{
	ID = id;
}


void Collider::draw()
{
	if (level != nullptr) {
		level->getGraphicsManager()->draw(path, position);
	}
}

void Collider::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{
	std::cout << ID << "is colliding with " << otherId << std::endl;
}



