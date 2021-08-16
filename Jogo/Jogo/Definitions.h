#pragma once

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define SPLASH_STATE_SHOW_TIME 4.0

#define HEIGHT 36
#define WIDTH 177

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Textures/splashBackground.png"
#define GAME_PAUSE_FILEPATH "Textures/pause.png"

#define GAME_OVER_BACKGROUND_FILEPATH "Textures/gameover.png"

#define GAME_TITLE_FILEPATH "Textures/title.png"
#define PLAY_BUTTON_FILEPATH "Textures/PlayButton.png"


enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f