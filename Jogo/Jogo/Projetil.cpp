#include "Projetil.h"

Projetil::Projetil(const int d, const float posx, const float posy): dir(d)
{
    initTextura();
    initSprite();
    sprite.setPosition(posx, posy);
}


Projetil::~Projetil()
{
}

void Projetil::initTextura()
{
    if (!textura.loadFromFile("Texturas/Ghost_projectil.png"))
    {
        cout << "Load Failed" << endl;
        system("pause");
    }
}

void Projetil::initSprite()
{
    sprite.setTexture(textura);    
}

void Projetil::update()
{
    if (dir == 0) {
        sprite.move(1.f, 0);
    }
    else {
        sprite.move(-1.f, 0);
    }

    cout << sprite.getPosition().x << "   " << sprite.getPosition().y << endl;
}
