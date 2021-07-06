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
    teste.setWindow(&window);

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

}

void Jogo::renderiza()
{
    window.clear();
    teste.draw();
    window.display();
}
