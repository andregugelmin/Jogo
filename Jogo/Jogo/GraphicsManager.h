#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>



class GraphicsManager
{
private:
	sf::RenderWindow* window;
	std::map<const std::string, sf::Texture*> textures;

	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;

public:
	GraphicsManager();
	~GraphicsManager();

	void display() const;
	void clear(int r = 0, int g = 0, int b = 0);
	void draw(const std::string& path, const sf::Vector2f position);

	bool loadTexture(const std::string& path);
	void loadTexture(std::string name, std::string path);

	sf::Texture& GetTexture(std::string name);
	void center(const sf::Vector2f center);

	void LoadFont(std::string name, std::string fileName);
	sf::Font& GetFont(std::string name);

	sf::RenderWindow* getWindow() const;
	void setWindow(sf::RenderWindow* w);
	const sf::Vector2f getSize(const std::string& path) const;
};

