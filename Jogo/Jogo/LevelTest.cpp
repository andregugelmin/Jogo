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
    player = new Player(sf::Vector2f(100.f, 400.f),"player");
    entitiesList.insert(player);
    entitiesList.insert(new Goblun(sf::Vector2f(100.f, 400.f), sf::Vector2f(0.f, 0.f), "enemy", player));
    entitiesList.insert(new Goblun(sf::Vector2f(400.f, 400.f), sf::Vector2f(0.f, 0.f), "enemy", player));
    entitiesList.insert(new SandSnake(sf::Vector2f(500.f, 400.f), sf::Vector2f(0.f, 0.f), "enemy2", player));
    entitiesList.insert(new GiantBat(sf::Vector2f(500.f, 400.f), sf::Vector2f(0.f, 0.f), "enemy3", player));

    entitiesList.initEntities(this, collisionManager);
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
