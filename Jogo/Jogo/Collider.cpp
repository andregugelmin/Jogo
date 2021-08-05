#include "Collider.h"
#include <iostream>

Collider::Collider(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile, const char* id): Entity(pos, vel, textureFile), ID(id)
{
}

Collider::~Collider()
{
}

const char* Collider::getID() const
{
	return ID;
}


void Collider::collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim)
{
	std::cout << ID << "is colliding with " << otherId << endl;
}



