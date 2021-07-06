#include "Teste.h"
#include "stdafx.h"

void Teste::initTextura()
{
    if (!textura.loadFromFile("Texturas/Bloco.jpg"))
    {
        cout << "Load Failed" << endl;
        system("pause");
    }
}

void Teste::initSprite()
{
    sprite.setTexture(textura);
    sprite.setScale(2.5f, 2.5f);
    sprite.setPosition(sf::Vector2f(100.f, 100.f));
}

Teste::Teste()
{
    initTextura();
    initSprite();
}

Teste::~Teste()
{
}
