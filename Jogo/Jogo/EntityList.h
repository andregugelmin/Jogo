#pragma once

#include "Entity.h"
#include "List.h"

class GraphicsManager;
class CollisionManager;
class LevelTest;

class EntityList
{
private:

    List<Entity*> list;

public:

    EntityList();
    ~EntityList();

    void insert(Entity* info);
    void removeEntity(Entity* info);

    void initEntities(LevelTest* lvl, CollisionManager& cm);
    void updateEntities(CollisionManager& cm);
    void drawEntities();
    void destroyEntities();
};
