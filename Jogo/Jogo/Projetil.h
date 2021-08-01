#pragma once
#include "Entidade.h"
class Projetil :
    public Entidade
{
private:

    int dir;

public:
    Projetil(const int d = 0,const float posx = 0, const float posy = 0);
    ~Projetil();

    void initTextura();
    void initSprite();
    
    void update();
};

