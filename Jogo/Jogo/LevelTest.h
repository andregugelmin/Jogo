#pragma once
#include "Entity.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "EntityList.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Projectile.h"

class LevelTest
{
private:
	bool isWindowClosed;
	GraphicsManager* graphicsManager;
	CollisionManager collisionManager;
	EntityList entitiesList;
	std::set<Collider*> deleteColliders;

	Player* player;

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

