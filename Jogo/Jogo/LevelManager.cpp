#include "LevelManager.h"
#include<iostream>
#include <stdlib.h> 
#include <time.h>
#include "GameState.h"
#include "GameOverState.h"
#include "Definitions.h"

namespace Nightmare {

    LevelManager::LevelManager() :
        isWindowClosed(false), levelChanged(false), graphicsManager(nullptr), player(nullptr)
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
        spawnRandomEnemies();


        initLevel(Level01);

    }

    void LevelManager::initLevel(char tm[HEIGHT][WIDTH])
    {
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
            {
                if (tm[i][j] == 'B') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/B.png", "tile"));

                if (tm[i][j] == 'C') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/C.png", "tile"));

                if (tm[i][j] == 'G') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/G.png", "tile"));

                if (tm[i][j] == 'H') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/H.png", "tile"));

                if (tm[i][j] == 'D') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32 + 25), "Textures/Tiles2/D.png", "tile"));

                if (tm[i][j] == 'E') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/E.png", "tile"));

                if (tm[i][j] == 'N') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/N.png", "tile"));

                if (tm[i][j] == 'O') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/O.png", "tile"));

                if (tm[i][j] == 'I') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/I.png", "tile"));

                if (tm[i][j] == 'K') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/K.png", "endLevel"));
                if (tm[i][j] == 'X') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/K.png", "endGame"));

                if (tm[i][j] == 'J') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/J.png", "tile"));

                if (tm[i][j] == 'L') tilesList.insert(new Obstacle(sf::Vector2f(j * 32, i * 32), "Textures/Tiles2/L.png", "tile"));

                if (tm[i][j] == '0') entitiesList.insert(new GiantBat(sf::Vector2f(j * 32, i * 32), "enemy3", player));

                if (tm[i][j] == ' ') continue;
            }

        entitiesList.initEntities(this, collisionManager);
        tilesList.initEntities(this, collisionManager);

        collisionManager.setTileMapCollisions(tm, HEIGHT, WIDTH);

    }

    
    void LevelManager::execute()
    {
        sf::Texture background;
        background.loadFromFile("Textures/Background.png");
        sf::Sprite sBg(background);

        sf::Event e;

        while (!isWindowClosed) {


            if (graphicsManager->getWindow()->pollEvent(e)) {
                if (e.type == sf::Event::Closed) {
                    isWindowClosed = true;
                }
            }

            //if (GameStates::eGameOver != _gameState)
            //{
            //    _gameState = GameStates::ePlaying;
            //}

            //if (sf::Event::KeyReleased == event.type)
            //{
            //    if (sf::Keyboard::P == event.key.code)
            //    {
            //        // Switch To Pause
            //        this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
            //    }
            //}

            for (Collider* it : deleteColliders) {

                entitiesList.removeEntity(it);
                collisionManager.removeCollider(it);
                delete it;

            }

            deleteColliders.clear();

            graphicsManager->clear();

            auto window = graphicsManager->getWindow();

            window->draw(sBg);


            tilesList.drawEntities();

            entitiesList.updateEntities();

            collisionManager.checkCollisions();

            entitiesList.updatePhysicsEntities();

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
    void LevelManager::changeLevel()
    {
        if (!levelChanged) {
            entitiesList.removeEntity(player);
            collisionManager.removeAllColliders();
            entitiesList.destroyEntities();
            tilesList.destroyEntities();
            entitiesList.insert(player);
            
            spawnRandomEnemies();
            

            collisionManager.addCollider(player);
            initLevel(Level02);
            deleteColliders.clear();
            player->setPosition(100, 900);
            levelChanged = true;
            execute();
            
        }     
        
    }
    void LevelManager::spawnRandomEnemies()
    {
        srand(time(NULL));

        int qtd1 = (rand() % 3) + 3;
        int qtd2 = (rand() & 3) + 3;

        for (int i = 0; i < qtd1; i++) {
            int posx = (rand() % 5000) + 300;
            int posy = (rand() % 200) + 700;

            entitiesList.insert(new Goblun(sf::Vector2f(posx, posy), "enemy", player));
        }

        for (int i = 0; i < qtd2; i++) {
            int posx2 = (rand() % 5000) + 300;
            int posy2 = (rand() % 200) + 500;

            entitiesList.insert(new SandSnake(sf::Vector2f(posx2, posy2), "enemy2", player));
        }

    }
};