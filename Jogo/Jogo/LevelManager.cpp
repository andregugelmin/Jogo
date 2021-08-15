#include "LevelManager.h"
#include "Definitions.h"
#include<iostream>

namespace Nightmare {


    LevelManager::LevelManager() :
        isWindowClosed(false), graphicsManager(nullptr), player(nullptr)
    {
    }

    LevelManager::~LevelManager()
    {
        player = nullptr;
    }

    void LevelManager::init(GraphicsManager& gm)
    {
        graphicsManager = &gm;
        entitiesList.insert(player);
        entitiesList.insert(new Goblun(sf::Vector2f(100.f, 100.f), "enemy", player));
        entitiesList.insert(new Goblun(sf::Vector2f(400.f, 100.f), "enemy", player));
        entitiesList.insert(new SandSnake(sf::Vector2f(500.f, 100.f), "enemy2", player));

        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
            {
                if (Level01[i][j] == 'B') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/2.png", "tile"));

                if (Level01[i][j] == 'C') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/4.png", "tile"));

                if (Level01[i][j] == 'G') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/G.png", "tile"));

                if (Level01[i][j] == 'H') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/H.png", "tile"));

                if (Level01[i][j] == 'D') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32 + 25), "Textures/Tiles2/D.png", "tile"));

                if (Level01[i][j] == 'I') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/I.png", "tile"));

                if (Level01[i][j] == 'K') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/K.png", "tile"));

                if (Level01[i][j] == 'J') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/J.png", "tile"));

                if (Level01[i][j] == 'L') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/L.png", "tile"));

                if (Level01[i][j] == '0') entitiesList.insert(new GiantBat(sf::Vector2f(j * 32, i * 32), "enemy3", player));

                if (Level01[i][j] == ' ') continue;
            }

        entitiesList.initEntities(this, collisionManager);
        tilesList.initEntities(this, collisionManager);

        collisionManager.setTileMapCollisions(Level01, HEIGHT, WIDTH);
    }

    void LevelManager::execute()
    {

        sf::Event e;

        while (!isWindowClosed) {


            if (graphicsManager->getWindow()->pollEvent(e)) {
                if (e.type == sf::Event::Closed) {
                    isWindowClosed = true;
                }
            }

            for (Collider* it : deleteColliders) {

                entitiesList.removeEntity(it);
                collisionManager.removeCollider(it);
                delete it;

            }

            deleteColliders.clear();

            graphicsManager->clear();

            tilesList.drawEntities();

            entitiesList.updateEntities(collisionManager);

            entitiesList.drawEntities();


            graphicsManager->display();

        }
    }


    void LevelManager::spawnElement(Collider* info)
    {
        if (info) {
            info->init(this, collisionManager);
            entitiesList.insert(info);
        }
    }

    void LevelManager::destroyElement(Collider* info)
    {
        deleteColliders.insert(info);
    }

    const EntityList LevelManager::getEntitiesList() const
    {
        return entitiesList;
    }

    GraphicsManager* LevelManager::getGraphicsManager() const
    {
        return graphicsManager;
    }

    CollisionManager* LevelManager::getCollisionManager()
    {
        return &collisionManager;
    }

    void LevelManager::setPlayer(Player* p)
    {
        player = p;
    }

    void LevelManager::setGraphicsManager(GraphicsManager* gm)
    {
        graphicsManager = gm;
    }
}