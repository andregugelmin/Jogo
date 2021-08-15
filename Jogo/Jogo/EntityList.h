#pragma once

#include "Entity.h"
#include "List.h"

namespace Nightmare {

    class GraphicsManager;
    class CollisionManager;
    class LevelManager;

    class EntityList
    {
    private:

        List<Entity*> list;

    public:

        EntityList();
        ~EntityList();

        void insert(Entity* info);
        void removeEntity(Entity* info);

        void initEntities(LevelManager* lvl, CollisionManager& cm);
        void updateEntities(CollisionManager& cm);
        void drawEntities();
        void destroyEntities();
    };
};
