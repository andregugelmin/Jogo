#pragma once

#include<set>
#include<math.h>
#include"SFML/Graphics.hpp"

class Collider;

#define H 17
#define W 177

class CollisionManager
{
private:
	std::set<Collider*> colliders;
	std::set<Collider*>::iterator it;
    char TileMap[H][W] = {
    "B                                                                                                                                                                              B",
    "B                                                                                       00000000000   000       00000                                                          B",
    "B                                                                                                                                                                              B",
    "B                                                                                                                                                                              B",
    "B                                                                                                                                                                              B",
    "B                                                                                   BBBBB    BBB   BBBBB    BBBBBBBB                                                           B",
    "B                                                                             BBBB                                                                                             B",
    "B                                                                                                                                                                              B",
    "B                                                                   BBBBBB                                                                                                     B",
    "B     0                          BB                                                                                                                                            B",
    "B                              BBBBBB          BBBB    BBB   BBB                                                                                                               B",
    "B                            BBBBBBBBBB                                                                                                                                        B",
    "B            BB            BBBBBBBBBBBBBB                                                                                                                                      B",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    };
public:
	CollisionManager();
	~CollisionManager();

	void addCollider(Collider* c);
	void removeCollider(Collider* c);
	void removeAllColliders();

	bool isColliding(Collider* c1, Collider* c2);
	void checkCollisions();
	void checkMapCollision(Collider* c);
};

