#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Fase1.h"

class Jogo
{
private:
	sf::RenderWindow window;
	Player player1;
	Enemy enemy1;
	Fase1 fase1;

public:
	Jogo();
	~Jogo();
	void Executar();
	void processaEventos();
	void atualiza();
	void renderiza();
};

