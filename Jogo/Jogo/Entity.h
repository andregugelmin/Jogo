#pragma once
#include "GraphicsManager.h"
#include "CollisionManager.h"

namespace Nightmare {
	class LevelManager;

	class Entity
	{
	protected:
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Vector2f dimensions;

		sf::Vector2f scale;

		const char* path;

		LevelManager* level;

	public:
		Entity(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const char* textureFile = nullptr);
		virtual ~Entity();

		virtual void init(LevelManager* lvl, CollisionManager& cm);
		virtual void update() = 0;
		virtual void updatePhysics();
		virtual void draw() = 0;

		void setPosition(const float x, const float y);
		void setVelocity(const float x, const float y);

		const sf::Vector2f getPosition() const;
		const sf::Vector2f getDimensions() const;
		const sf::Vector2f getVelocity() const;

		void setLevel(LevelManager* lvl);
		void setScale(sf::Vector2f s);

	};
};

