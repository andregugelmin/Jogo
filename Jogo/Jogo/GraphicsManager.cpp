#include "GraphicsManager.h"
#include <iostream>

GraphicsManager::GraphicsManager() : window()	
{

}

GraphicsManager::~GraphicsManager()
{
	if (window) delete window;

	for (auto i : textures) {
		delete i.second;
	}
}

void GraphicsManager::display() const
{
	window->display();
}

void GraphicsManager::clear(int r, int g, int b)
{
	window->clear(sf::Color(r, g, b));
}

void GraphicsManager::draw(const std::string& path, const sf::Vector2f position)
{

	if (textures.count(path) == 0) {
		std::cout << "Could not load image from " << path << std::endl;
		exit(121);
	}

	sf::Texture* text = textures[path];

	sf::Sprite sprite;

	sprite.setTexture(*text);

	sprite.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);

	sprite.setPosition(position.x, position.y);
	
	window->draw(sprite);
}

bool GraphicsManager::loadTexture(const std::string& path)
{
	if (textures.count(path) == 1) return true;
	else {
		sf::Texture* text = new sf::Texture();
		if (!text->loadFromFile(path)) {
			std::cout << "Could not load image from " << path << std::endl;
			exit(120);
		}

		textures.emplace(path, text);
		return true;
	}
}

void GraphicsManager::loadTexture(std::string name, std::string path)
{
		sf::Texture tex;

		if (tex.loadFromFile(path))
		{
			this->_textures[name] = tex;
		}
}

sf::Texture& GraphicsManager::GetTexture(std::string name)
{
	return this->_textures.at(name);
}

void GraphicsManager::center(const sf::Vector2f center)
{
	camera.setCenter(sf::Vector2f(center.x, center.y - 150));
	window->setView(camera);
}

void GraphicsManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->_fonts[name] = font;
	}
}

sf::Font& GraphicsManager::GetFont(std::string name)
{
	return this->_fonts.at(name);
}

sf::RenderWindow* GraphicsManager::getWindow() const
{
	return window;
}

void GraphicsManager::setWindow(sf::RenderWindow* w)
{
	window = w;
	window->setFramerateLimit(60);

	window->setKeyRepeatEnabled(false);
}

const sf::Vector2f GraphicsManager::getSize(const std::string& path) const
{
	if (textures.count(path) == 0) {
		std::cout << "Could not load image from " << path << std::endl;
		exit(121);
	}

	sf::Vector2u dim = (textures.at(path))->getSize();
	return sf::Vector2f(dim.x, dim.y);
}

