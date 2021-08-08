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
		auto paux2 = paux1;
		paux2++;
		
		for (; paux2 != colliders.end(); paux2++) {
			Collider* c2 = *paux2;			
			if (c1 && c2) {
				if (isColliding(c1, c2)) {
					//std::cout << c1 << " id: " << c1->getID() << "  Collided with  " << c2 << " id: " << c2->getID() << std::endl;
					c1->collide(c2->getID(), c2->getPosition(), c2->getPosition());
					c2->collide(c1->getID(), c1->getPosition(), c1->getPosition());
				}
			}
		}
			
	}
}


