#include "Obstacle.h"
#include "LevelManager.h"

namespace Nightmare {

	Obstacle::Obstacle(sf::Vector2f pos, const char* textureFile, const char* id) :
		Collider(pos, textureFile, id)
	{
	}

	Obstacle::~Obstacle()
	{
	}

	void Obstacle::update()
	{

	}
};


