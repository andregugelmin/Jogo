#pragma once

#include "Entity.h"
#include "List.h"

class GraphicsManager;
class CollisionManager;

class EntityList
{
private:

    List<Entity*> list;

public:

    EntityList();
    ~EntityList();

    void insert(Entity* info);


    void initEntities(GraphicsManager& gm, CollisionManager& cm);
    void updateEntities(GraphicsManager& gm, CollisionManager& cm);
    void drawEntities(GraphicsManager& gm);
    void destroyEntities();
};
