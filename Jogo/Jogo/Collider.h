#pragma once
#include "Entity.h"

class Collider: public Entity
{
protected:
	const char* ID;

public:
	Collider(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr, const char* id = nullptr);
	virtual ~Collider();


	virtual void init(LevelManager* lvl, CollisionManager& cm);

	virtual void draw() override;

	const char* getID() const;
	void setId(const char* id);

	virtual void collide(const char* otherId, sf::Vector2f otherPos, sf::Vector2f otherDim);
};

