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
        "GZZZZZZZZZCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCH",
        "GZZZZZZZZZCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCH",
        "GZZZZZZZZZCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCH",
        "GZZZZZZZZZCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCH",
        "GZZZZZZZZZCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCH",
        "GZZZZZZZZZCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCH",
        "GZZZZZZZZZLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLM",
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
        "G                                                                                              BB                                                                              H",
        "G                                                                                                                                                                              H",
        "G                                                                                         BB        BB                                                                         H",
        "G                                                                                                                                                                   0          H",
        "G                                                                                     BB                 BBBBB                                                                 H",
        "G                                                                                 BBBB                          B              E      E   E    E       E                       H",
        "G                                BB                  BBB   BBB            E                                                    E      E   E    E       E     E                 H",
        "G                              B               BBB                        E                                         BB         E      E   E    E       E     E   E             H",
        "G                                                                         E                                                    E      E   E    E       E     E   E         K   H",
        "CBBBBBBBBBBBBBBBBBBBBBBBBBBBBJ         IBBBBBJ                     IBBBBBBBBBBBBBJ                                         IBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCG         HCCCCCG                     HCCCCCCCCCCCCCG                                         HCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCGDDDDDDDDDHCCCCCGDDDDDDDDDDDDDDDDDDDDDHCCCCCCCCCCCCCGDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDHCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
        "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
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
