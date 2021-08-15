#pragma once

#include<set>
#include<math.h>
#include"SFML/Graphics.hpp"
#include "Definitions.h"

namespace Nightmare {
	class Collider;


	class CollisionManager
	{
	private:
		std::set<Collider*> colliders;
		char tileMap[HEIGHT][WIDTH];

	public:
		CollisionManager();
		~CollisionManager();

		void addCollider(Collider* c);
		void removeCollider(Collider* c);
		void removeAllColliders();

		bool isColliding(Collider* c1, Collider* c2);
		void checkCollisions();
		void checkMapCollision(Collider* c);

		void setTileMapCollisions(char tm[][WIDTH], int h, int w);
	};
};
