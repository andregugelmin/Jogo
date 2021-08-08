#pragma once

#include<set>
#include<math.h>
#include"SFML/Graphics.hpp"

class Collider;

class CollisionManager
{
private:
	std::set<Collider*> colliders;
	std::set<Collider*>::iterator it;

public:
	CollisionManager();
	~CollisionManager();

	void addCollider(Collider* c);
	void removeCollider(Collider* c);
	void removeAllColliders();

	bool isColliding(Collider* c1, Collider* c2);
	void checkCollisions();
};

