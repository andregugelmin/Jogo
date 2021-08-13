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
    player = new Player(sf::Vector2f(200.f, 0.f),"player");
    entitiesList.insert(player);
    //entitiesList.insert(new Goblun(sf::Vector2f(100.f, 400.f), sf::Vector2f(0.f, 0.f), "enemy", player));
    //entitiesList.insert(new Goblun(sf::Vector2f(400.f, 400.f), sf::Vector2f(0.f, 0.f), "enemy", player));
    //entitiesList.insert(new SandSnake(sf::Vector2f(500.f, 400.f), sf::Vector2f(0.f, 0.f), "enemy2", player));
    //entitiesList.insert(new GiantBat(sf::Vector2f(500.f, 400.f), sf::Vector2f(0.f, 0.f), "enemy3", player));    

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            if (Level01[i][j] == 'B') entitiesList.insert(new Obstacle(sf::Vector2f(j * 32 + 16, i * 32 + 16), sf::Vector2f(0.f, 0.f),"Textures/Tiles2/1.png", "tile")); //mapeia os pixels da imagem (posx, posy, tamanhoimagem em x, tamanhoimagem em y)

            if (Level01[i][j] == 'C') entitiesList.insert(new Obstacle(sf::Vector2f(j * 32 + 16, i * 32 + 16), sf::Vector2f(0.f, 0.f), "Textures/Tiles2/4.png", "tile"));

            if (Level01[i][j] == 'D') entitiesList.insert(new Obstacle(sf::Vector2f(j * 32 + 16, i * 32 + 16), sf::Vector2f(0.f, 0.f), "Textures/Tiles2/2.png", "tile"));

            if (Level01[i][j] == '0') entitiesList.insert(new Obstacle(sf::Vector2f(j * 32 + 16, i * 32 + 16), sf::Vector2f(0.f, 0.f), "Textures/Tiles2/3.png", "tile"));

            if (Level01[i][j] == ' ') continue;
        }

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
