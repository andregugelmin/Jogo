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
#include "Definitions.h"


namespace Nightmare {
    class LevelManager {

    private:
        bool isWindowClosed;
        GraphicsManager* graphicsManager;
        CollisionManager collisionManager;
        EntityList entitiesList;
        EntityList tilesList;
        std::set<Collider*> deleteColliders;

        Player* player;

        char Level01[HEIGHT][WIDTH] = {
        "MLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLM",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                            BBB   BBB    BBBBB                                                                H",
        "G                                                                                         B                                                                                    H",
        "G                                                                                                                                                                   0          H",
        "G                                                                                     B                             BBBB                                                       H",
        "G                                                                                 BBBB                                                                                         H",
        "G                             BB   BBB            BBBB    BBB   BBB             B                                                                                              H",
        "G                           B                  BBB                                                                                                                             H",
        "G                                                                         E                                                    E      E       E                            K   H",
        "CBBBBBBBBBBBBBBBBBBBBBBBBBBBBJ         IBBBBBJ                     IBBBBBBBBBBBBBJ                                         IBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCG         HCCCCCG                     HCCCCCCCCCCCCCG                                         HCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCGDDDDDDDDDHCCCCCGDDDDDDDDDDDDDDDDDDDDDHCCCCCCCCCCCCCGDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDHCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBBBBBBBBBCCCCCCCBBBBBBBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        };

        char Level02[HEIGHT][WIDTH] = {
         "MLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLM",
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
         "C            BB            BBCCCCCCCCCCBB                             E    E     E   E    E     E    E       E     E   E                                                    K  C",
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
        void setGraphicsManager(GraphicsManager* gm);
    };
};
