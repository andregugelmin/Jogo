#pragma once
#include "Entity.h"

class Collider: public Entity
{
protected:
	const char* ID;

public:
	Collider(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr);
	virtual ~Collider();

	const char* getID() const;
	virtual void update(GraphicsManager& gm) = 0;
	virtual void updatePhysics() = 0;
	virtual void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim);
};

