#pragma once
#include "GraphicsManager.h"
#include "CollisionManager.h"

class LevelTest;

class Entity
{
protected:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f dimensions;

	sf::Vector2f scale;

	const char* path;

	LevelTest* level;

public:
	Entity(sf::Vector2f pos = sf::Vector2f(0.f,0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr);
	virtual ~Entity();

	virtual void init(LevelTest* lvl, CollisionManager& cm);
	virtual void update() = 0;
	virtual void updatePhysics();
	virtual void draw() = 0;

	void setPosition(const float x, const float y);
	
	const sf::Vector2f getPosition() const;
	const sf::Vector2f getDimensions() const;

	void setLevel(LevelTest* lvl);
	void setScale(sf::Vector2f s);
	
};

