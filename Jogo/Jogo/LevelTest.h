#pragma once
#include "Entity.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "EntityList.h"
#include "Player.h"
#include "Goblun.h"
#include "SandSnake.h"
#include "GiantBat.h"
#include "Projectile.h"
#include "Obstacle.h"

#define H 17
#define W 177

class LevelTest
{
private:
	bool isWindowClosed;
	GraphicsManager* graphicsManager;
	CollisionManager collisionManager;
	EntityList entitiesList;
	std::set<Collider*> deleteColliders;

	Player* player;

	char Level01[H][W]= {
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
	LevelTest();
	~LevelTest();

	void init(GraphicsManager& gm);
	void execute();
	void spawnElement(Collider* info);
	void destroyElement(Collider* info);

	const EntityList getEntitiesList() const;
	GraphicsManager* getGraphicsManager() const;
	CollisionManager* getCollisionManager();
	void setPlayer(Player* p);
};

