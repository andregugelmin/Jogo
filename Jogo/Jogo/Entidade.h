#pragma once
#include "stdafx.h"
class Entidade
{
protected:
	sf::Texture textura;
	sf::Sprite sprite;
	sf::Image image;
	sf::RenderWindow* window;

public:
	Entidade();
	~Entidade();
	void setWindow(sf::RenderWindow* win);
	sf::RenderWindow* getWindow() const;
	void draw();
};

