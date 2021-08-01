#include "Main.h"

Main::Main():
    isWindowClosed(false)
{
    player = new Player(sf::Vector2f(200.f, 0.f));
    entitiesList.insert(player);
    entitiesList.insert(new Enemy1(sf::Vector2f(200.f, 400.f), sf::Vector2f(0.f, 0.f), player));
    entitiesList.insert(new Enemy1(sf::Vector2f(400.f, 400.f), sf::Vector2f(0.f, 0.f), player));
    entitiesList.insert(new Enemy1(sf::Vector2f(600.f, 400.f), sf::Vector2f(0.f, 0.f), player));

    entitiesList.initEntities(graphicsManager);
   

    execute();
}

Main::~Main()
{
    player = nullptr;
}

void Main::execute()
{   

    sf::Event e;

    while (!isWindowClosed) {


        if (graphicsManager.getWindow()->pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                isWindowClosed = true;
            }
        }

        graphicsManager.clear();

        entitiesList.updateEntities(graphicsManager);


        entitiesList.drawEntities(graphicsManager);

        graphicsManager.display();
    }
}
