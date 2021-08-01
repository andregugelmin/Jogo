#include "Jogo.h"

Jogo::Jogo() :
    window(sf::VideoMode(800, 600), "Jogo")
{
    window.setFramerateLimit(60);
    Executar();
}

Jogo::~Jogo()
{

}

void Jogo::Executar()
{
    fase1.setWindow(&window);
    player1.setWindow(&window);
    enemy1.setWindow(&window);
    enemy1.setTarget(&player1);
    enemy1.getProjetil()->setWindow(&window);

    while (window.isOpen())
    {
        processaEventos();
        atualiza();
        renderiza(); 
    }
}

void Jogo::processaEventos()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Jogo::atualiza()
{
    player1.update();
    enemy1.update();
}


void Jogo::renderiza()
{
    window.clear();
    fase1.initScenery();
    player1.draw();
    enemy1.draw();
    enemy1.getProjetil()->draw();
    window.display();
}
