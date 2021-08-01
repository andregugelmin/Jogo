#include "Entidade.h"

Entidade::Entidade(): window(NULL)
{
}

Entidade::~Entidade()
{
}

void Entidade::setWindow(sf::RenderWindow* win)
{
	window = win;
}

sf::RenderWindow* Entidade::getWindow() const
{
	return window;
}

void Entidade::draw()
{
	window->draw(sprite);
}
