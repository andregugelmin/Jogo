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
    player1.setWindow(&window);
    enemy1.setWindow(&window);
    enemy1.setTarget(&player1);

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
    player1.move();
    enemy1.atualiza();
}

void Jogo::renderiza()
{
    window.clear();
    player1.draw();
    enemy1.draw();
    window.display();
}
