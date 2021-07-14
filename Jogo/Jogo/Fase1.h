#pragma once
#include "Entidade.h"
class Fase1 : public Entidade
{
private:
	void initTextura();
	void initSprite();
	sf::Texture tBackGround;
	sf::Sprite sBackGround;
	
public:

	Fase1();
	~Fase1();
	void initScenery();
};
	

