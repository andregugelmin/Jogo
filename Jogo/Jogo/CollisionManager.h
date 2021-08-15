#pragma once

#include<set>
#include<math.h>
#include"SFML/Graphics.hpp"

namespace Nightmare {
	class Collider;

#define H 17
#define W 177

	class CollisionManager
	{
	private:
		std::set<Collider*> colliders;
		char tileMap[H][W];

	public:
		CollisionManager();
		~CollisionManager();

		void addCollider(Collider* c);
		void removeCollider(Collider* c);
		void removeAllColliders();

		bool isColliding(Collider* c1, Collider* c2);
		void checkCollisions();
		void checkMapCollision(Collider* c);

		void setTileMapCollisions(char tm[][W], int h, int w);
	};
};
