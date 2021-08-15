#include "CollisionManager.h"
#include "Collider.h"
#include<iostream>
CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::addCollider(Collider* c)
{
	colliders.insert(c);
}


void CollisionManager::removeCollider(Collider* c)
{
	colliders.erase(c);
}

void CollisionManager::removeAllColliders()
{
	colliders.clear();
}

bool CollisionManager::isColliding(Collider* c1, Collider* c2)
{
	if (c1 == c2) return false;

	sf::Vector2f pos1 = c1->getPosition();
	sf::Vector2f pos2 = c2->getPosition();
	sf::Vector2f dim1 = c1->getDimensions();
	sf::Vector2f dim2 = c2->getDimensions();
	
	return (fabs(pos1.x - pos2.x) < (dim1.x + dim2.x) / 2.f) && (fabs(pos1.y - pos2.y) < (dim1.y + dim2.y) / 2.f);
	
}


void CollisionManager::checkCollisions()
{
	for (auto paux1 = colliders.begin(); paux1 != colliders.end(); paux1++) {				
		Collider* c1 = *paux1;		
		checkMapCollision(c1);

		auto paux2 = paux1;
		paux2++;
		
		for (; paux2 != colliders.end(); paux2++) {
			Collider* c2 = *paux2;			
			if (c1 && c2) {
				if (isColliding(c1, c2)) {
					c1->collide(c2->getID(), c2->getPosition(), c2->getDimensions());
					c2->collide(c1->getID(), c1->getPosition(), c1->getDimensions());
				}
			}
		}
			
	}
}

void CollisionManager::checkMapCollision(Collider* c)
{
	sf::Vector2f pos = c->getPosition();
	sf::Vector2f dim = c->getDimensions();
	
	unsigned int top = static_cast<unsigned int>(ceil((pos.y - dim.y/2) / 32));
	unsigned int bottom = static_cast<unsigned int>(ceil((pos.y + dim.y/2) / 32));
	unsigned int left = static_cast<unsigned int>(floor((pos.x- dim.x/2) / 32));
	unsigned int right = static_cast<unsigned int>(ceil((pos.x + dim.x/2) / 32));

	if (pos.x >= 0 && pos.y >= 0 && pos.x < 177 * 32 && pos.y < 17 * 32) {

		for (unsigned int i = top; i <= bottom; i++)
			for (unsigned int j = left; j <= right; j++)
			{
				if (tileMap[i][j] == 'B' || tileMap[i][j] == 'C' || tileMap[i][j] == 'D')
				{
					
					c->collide("tile", sf::Vector2f(j * 32, i * 32), sf::Vector2f(32, 32));
				}
			}
	}
}

void CollisionManager::setTileMapCollisions(char tm[][W], int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			tileMap[i][j] = tm[i][j];
		}
	}
}


