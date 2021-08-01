#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>



class GraphicsManager
{
private:
	sf::RenderWindow* window;
	sf::View camera;
	std::map<const std::string, sf::Texture*> textures;

public:
	GraphicsManager();
	~GraphicsManager();

	void display() const;
	void clear(int r = 0, int g = 0, int b = 0);
	void draw(const std::string& path, const sf::Vector2f position);

	bool loadTexture(const std::string& path);

	void center(const sf::Vector2f center);

	sf::RenderWindow* getWindow() const;

	const sf::Vector2f getSize(const std::string& path) const;
};

