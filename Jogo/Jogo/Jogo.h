#pragma once
#include "stdafx.h"
#include "Teste.h"
class Jogo
{
private:
	sf::RenderWindow window;
	Teste teste;

public:
	Jogo();
	~Jogo();
	void Executar();
	void processaEventos();
	void atualiza();
	void renderiza();

};

