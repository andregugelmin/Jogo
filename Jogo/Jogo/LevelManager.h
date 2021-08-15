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
    "C                                                                                            BBB   BBB    BBBBB                                                                C",
    "C                                                                                         B                                                                                    C",
    "C                                                                                       BB                                                                            0        C",
    "C                                                                                     B                             BBBB                                                       C",
    "C                                                                                 BBBB                                                                                         C",
    "C                             BB   BBB            BBBB    BBB   BBB             B                                                                                              C",
    "C                           B                  BBB                                                                                                                             C",
    "C                                                                         E                                                    E      E       E                            F   C",
    "CBBBBBBBBBBBBBBBBBBBBBBBBBBBBB         BBBBBBB                     BBBBBBBBBBBBBBB                                         BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC         CCCCCCC                     CCCCCCCCCCCCCCC                                         CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC         CCCCCCC                     CCCCCCCCCCCCCCC                                         CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDCCCCCCCDDDDDDDDDDDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    };

   char Level02[H][W] = {
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                                                                                                              C",
    "C                                                                                   BBBBB    BBB   BBBBB    BBBBBBBB                                                           C",
    "C                                                                             BBBB                                                                                             C",
    "C                                                                                                                      BBB                                                     C",
    "C                                                                   BBBBBB                                                                                           0         C",
    "C                                BB                                                                                                                                            C",
    "C                              BBCCBB          BBBB    BBB   BBB                                                                                                               C",
    "C                            BBCCCCCCBB                                                                                         BBB    BBB                                     C",
    "C            BB            BBCCCCCCCCCCBB                             E    E     E   E    E     E    E       E     E   E                                                    F  C",
    "CBBBBBBBBBBBBCCBBBBBBBBBBBBCCCCCCCCCCCCCCBBBBB                     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB               BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC               CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC               CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
    "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
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

