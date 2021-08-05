#pragma once
#include "Entity.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "EntityList.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"

class Main
{
private:
	bool isWindowClosed;
	GraphicsManager graphicsManager;
	CollisionManager collisionManager;
	EntityList entitiesList;

	Player* player;

public:
	Main();
	~Main();

	void execute();

};

