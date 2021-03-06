#pragma once
#include "Collider.h"

namespace Nightmare {
    class Obstacle :
        public Collider
    {
    protected:


    public:
        Obstacle(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr);
        ~Obstacle();

        void update();

    };
};

