#pragma once
#include "stdafx.h"
#include "GraphicsManager.h"

class Entity
{
protected:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f dimensions;

	const char* path;


public:
	Entity(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile = nullptr);
	virtual ~Entity();

	virtual void init(GraphicsManager& gm);
	virtual void update(GraphicsManager& gm);
	virtual void draw(GraphicsManager& gm);
	
	const sf::Vector2f getPosition() const;
	const sf::Vector2f getDimensions() const;
};

