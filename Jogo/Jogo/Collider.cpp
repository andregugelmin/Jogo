#include "Collider.h"
#include "LevelManager.h"
#include <iostream>

namespace Nightmare {

	Collider::Collider(sf::Vector2f pos, const char* textureFile, const char* id) : Entity(pos, textureFile), ID(id)
	{
	}

	Collider::~Collider()
	{
	}

	void Collider::init(LevelManager* lvl, CollisionManager& cm)
	{
		if (lvl != nullptr) {
			setLevel(lvl);

			level->getGraphicsManager()->loadTexture(path);
			dimensions = level->getGraphicsManager()->getSize(path);
		}

		if (ID != "tile") cm.addCollider(this);
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
	}

};



