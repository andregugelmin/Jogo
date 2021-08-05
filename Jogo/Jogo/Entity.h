#pragma once
#include "stdafx.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"

class Entity
{
protected:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f dimensions;

	const char* path;


public:
	Entity(sf::Vector2f pos = sf::Vector2f(0.f,0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr);
	virtual ~Entity();

	virtual void init(GraphicsManager& gm, CollisionManager& cm);
	virtual void update(GraphicsManager& gm) = 0;
	virtual void updatePhysics() = 0;
	virtual void draw(GraphicsManager& gm);
	
	const sf::Vector2f getPosition() const;
	const sf::Vector2f getDimensions() const;

	
};

