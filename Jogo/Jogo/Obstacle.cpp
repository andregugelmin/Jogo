#include "Obstacle.h"


Obstacle::Obstacle(sf::Vector2f pos, sf::Vector2f vel, const char* textureFile, const char* id, sf::Vector2f targetPos) : position(pos),velocity(vel),path("Textures/Tiles/2.png"),level(nullptr)
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::update()
{
	
}

void Obstacle::drawObs()
{
	for (auto itr = lvl.begin(); itr != lvl.end(); itr++) {
		window.draw(*itr->second.sprite);
	}
}

void Obstacle::init(LevelTest* lvl, CollisionManager& cm)
{
	if (lvl != nullptr) {
		setLevel(lvl);

		//level->getGraphicsManager()->loadTexture(path);
		//dimensions = level->getGraphicsManager()->getSize(path);
	}
}

void Obstacle::Collision(int dir)
{
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
		{
			if (TileMap[i][j] == 'B')
			{
				if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
				if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
				if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
				if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
			}

			if (TileMap[i][j] == '0')
			{
				TileMap[i][j] = ' ';
			}

		}

}

char Obstacle::TileMap[15][80] = {

"B                                                                             B",
"B                                                                             B",
"B                                                                             B",
"B                                    000                                      B",
"B                                                                             B",
"B                                                                             B",
"B                                                                             B",
"B     0                         BB                                            B",
"B                             BB  BB                                          B",
"B                           BB      BB                                        B",
"B            BB           BB          BB                                      B",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};
