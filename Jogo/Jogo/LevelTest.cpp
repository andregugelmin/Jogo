#include "LevelTest.h"
#include<iostream>

LevelTest::LevelTest() :
    isWindowClosed(false), graphicsManager(nullptr), player(nullptr)
{
}

LevelTest::~LevelTest()
{
    player = nullptr;
}

void LevelTest::init(GraphicsManager& gm)
{
    graphicsManager = &gm;
    entitiesList.insert(player);
    entitiesList.insert(new Goblun(sf::Vector2f(100.f, 100.f), "enemy", player));
    entitiesList.insert(new Goblun(sf::Vector2f(400.f, 100.f), "enemy", player));
    entitiesList.insert(new SandSnake(sf::Vector2f(500.f, 100.f), "enemy2", player));    

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            if (Level01[i][j] == 'B') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32 ), "Textures/Tiles2/1.png", "tile")); 

            if (Level01[i][j] == 'C') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32 ), "Textures/Tiles2/4.png", "tile"));

            if (Level01[i][j] == 'D') tilesList.insert(new Obstacle(sf::Vector2f(j * 32 , i * 32 ), "Textures/Tiles2/2.png", "tile"));

            if (Level01[i][j] == '0') entitiesList.insert(new GiantBat(sf::Vector2f(j * 32 , i * 32 ), "enemy3", player));

            if (Level01[i][j] == ' ') continue;
        }

    entitiesList.initEntities(this, collisionManager);
    tilesList.initEntities(this, collisionManager);

    collisionManager.setTileMapCollisions(Level01, H, W);
}

void LevelTest::execute()
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


void LevelTest::spawnElement(Collider* info)
{
    if (info) {
        info->init(this, collisionManager);
        entitiesList.insert(info);
    }
}

void LevelTest::destroyElement(Collider* info)
{
    deleteColliders.insert(info);
}

const EntityList LevelTest::getEntitiesList() const
{
    return entitiesList;
}

GraphicsManager* LevelTest::getGraphicsManager() const
{
    return graphicsManager;
}

CollisionManager* LevelTest::getCollisionManager()
{
    return &collisionManager;
}

void LevelTest::setPlayer(Player* p)
{
    player = p;
}
