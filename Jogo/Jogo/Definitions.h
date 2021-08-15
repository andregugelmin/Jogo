#pragma once

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Textures/splashBackground.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Textures/sky.png"
#define GAME_BACKGROUND_FILEPATH "Textures/bgcar.png"
#define GAME_PAUSE_FILEPATH "Textures/pause.png"

#define GAME_OVER_BACKGROUND_FILEPATH "Textures/gameover.png"

#define GAME_TITLE_FILEPATH "Textures/title.png"
#define PLAY_BUTTON_FILEPATH "Textures/PlayButton.png"

#define CAR_FILEPATH "Textures/red.png"
#define ICON_FILEPATH "Textures/redicon.png"

#define HORN_PATH "Textures/239030__poyekhali__horn-2.ogg"

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f