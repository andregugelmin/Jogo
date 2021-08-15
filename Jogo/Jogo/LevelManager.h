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

class LevelManager
{
private:
	bool isWindowClosed;
	GraphicsManager* graphicsManager;
	CollisionManager collisionManager;
	EntityList entitiesList;
    EntityList tilesList;
	std::set<Collider*> deleteColliders;

	Player* player;

	char Level01[H][W]= {
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                   BBBBB    BBB   BBBBB    BBBBBBBB                                                           C",
    "C                                                                             BBBB                                                                                             C",
    "C                                                                                                                                                                              C",
    "C                                                                   BBBBBB                                                                                           0         C",
    "C                                BB                                                                                                                                            C",
    "C                              BBCCBB          BBBB    BBB   BBB                                                                                                               C",
    "C                            BBCCCCCCBB                                                                                                                                        C",
    "C            BB            BBCCCCCCCCCCBB                                                                                                                                      C",
    "CBBBBBBBBBBBBCCBBBBBBBBBBBBCCCCCCCCCCCCCCBBBBB                     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    };

   char Level02[H][W] = {
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                   BBBBB    BBB   BBBBB    BBBBBBBB                                                           C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                  0                           C",
    "C                                                                                                                                                                              C",
    "C                              BBCCBB          BBBB    BBB   BBB                                                                                                               C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "CBBBBBBBBBBBBCCBBBBBBBBBBBBCCCCCCCCCCCCCCBBBBB                     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    };



public:
	LevelManager();
	~LevelManager();

	void init(GraphicsManager& gm);
	void execute();
	void spawnElement(Collider* info);
	void destroyElement(Collider* info);

	const EntityList getEntitiesList() const;
	GraphicsManager* getGraphicsManager() const;
	CollisionManager* getCollisionManager();
	void setPlayer(Player* p);
};

