#pragma once

#include "Entity.h"
#include "List.h"

class GraphicsManager;

class EntityList
{
private:

    List<Entity*> list;

public:

    EntityList();
    ~EntityList();

    void insert(Entity* info);


    void initEntities(GraphicsManager& gm);
    void updateEntities(GraphicsManager& gm);
    void drawEntities(GraphicsManager& gm);
    void destroyEntities();
};
