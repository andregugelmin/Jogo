//PARTE DO BACKGROUND 
//setei o tamanho da windows em 1024, 550

t2.loadFromFile("resources/BG.png");

		Sprite sBg(t2);
		
		
		
		window.draw(sBg); //(tem que ser implementado dps do windows.clear
		
		
//PARTE DO MAPA, ainda vou colocar bonitinho mais figuras no mapa e mais tipos de obstaculos

float offsetX = 0, offsetY = 0;


const int H = 17;
const int W = 177;


String TileMap[H] = {

"B                                                                                                                                                                              B",
"B                                                                                       00000000000   000       00000                                                          B",
"B                                                                                                                                                                              B",
"B                                                                                                                                                                              B",
"B                                                                                                                                                                              B",
"B                                                                                   BBBBB    BBB   BBBBB    BBBBBBBB                                                           B",
"B                                                                             BBBB                                                                                             B",
"B                                                                                                                                                                              B",
"B                                                                   BBBBBB                                                                                                     B",
"B     0                          BB                                                                                                                                            B",
"B                              BBBBBB          BBBB    BBB   BBB                                                                                                               B",
"B                            BBBBBBBBBB                                                                                                                                        B",
"B            BB            BBBBBBBBBBBBBB                                                                                                                                      B",
"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",

};

//DESENHANDO MAPA

t2.loadFromFile("resources/BG.png");

		Sprite sBg(t2);

for (int i = 0; i < H; i++)
	for (int j = 0; j < W; j++)
	{
		if (TileMap[i][j] == 'B' ) rectangle.setTextureRect(IntRect(332, 205, 71, 35)); //mapeia os pixels da imagem (posx, posy, tamanhoimagem em x, tamanhoimagem em y)

		if (TileMap[i][j] == 'C') rectangle.setTextureRect(IntRect(332, 205, 71, 35));

		if (TileMap[i][j] == 'D') rectangle.setTextureRect(IntRect(415, 191, 44, 63));

		if (TileMap[i][j] == '0') rectangle.setTextureRect(IntRect(823, 79, 15, 15));

		if (TileMap[i][j] == ' ') continue;

		rectangle.setPosition(j * 32 - offsetX, i * 32 - offsetY);
		window.draw(rectangle);
	}



//PLAYER COLIDINDO COM O MAPA


void update(float time)// FUNÇÃO QUE CHAMA COLISAO UPDATE DE MOVIMENTO DO PLAYER 
		{

			rect.left += dx * time;
			Collision(0);

			if (!onGround) dy = dy + 0.0005 * time;
			rect.top += dy * time;
			onGround = false;
			Collision(1);

			sprite.setTextureRect(IntRect(250, 0, 53, 100));

			sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

			dx = 0;
		}
		
		
		
		
		
void Collision(int dir)
		{
			for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
				for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
				{
					if (TileMap[i][j] == 'B' || TileMap[i][j] == 'C' || TileMap[i][j] == 'D')
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

