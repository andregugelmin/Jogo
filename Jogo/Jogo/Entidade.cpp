#include "Entidade.h"

Entidade::Entidade()
{
}

Entidade::~Entidade()
{
}

void Entidade::setWindow(sf::RenderWindow* win)
{
	window = win;
}

void Entidade::draw()
{
	window->draw(sprite);
}
