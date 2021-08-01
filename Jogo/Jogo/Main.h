#pragma once
#include "Entity.h"
#include "GraphicsManager.h"
#include "EntityList.h"
#include "Player.h"
#include "Enemy1.h"

class Main
{
private:
	bool isWindowClosed;
	GraphicsManager graphicsManager;
	EntityList entitiesList;

	Player* player;

public:
	Main();
	~Main();

	void execute();

};

