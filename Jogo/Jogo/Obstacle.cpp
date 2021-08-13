#include "Obstacle.h"
#include "LevelTest.h"

Obstacle::Obstacle(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile, const char* id): 
	Collider(pos, vel, textureFile, id)
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::update()
{
	
}


