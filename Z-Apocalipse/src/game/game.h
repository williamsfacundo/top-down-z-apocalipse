#ifndef GAME_H
#define GAME_H

#include "main_menu.h"
#include "credits.h"
#include "options_menu.h"
#include "..\gameplay\scene_manager.h"
#include "..\gameplay\gameplay.h"
#include "..\gameplay\upgrader.h"
#include "..\gameplay\tutorial.h"
#include "..\gameplay\end_game.h"
#include "..\gameplay\pause_menu.h"

namespace Z_APOCALIPSE 
{
	class Game
	{
	private:
		const char* title = "Z-APOCALIPSE";
		const char* mainMenuTexts[maxMainMenuButtons] = { "PLAY", "OPTIONS", "CREDITS", "EXIT" };
		const char* optionsMenuText[maxOptionsMenuButtons] = { "800 x 450", "1280 x 720", "FULL SCREEN", "MENU"};
		const char* versionText = "v1.0";

		const short fps = 60;	

		const float versionYPercentage = 0.85f;
		const float versionXPercentage = 0.85f;
		const float versionSizeDivider = 20.0f;

		const Scenes initialScene = Scenes::MAIN_MENU; 	
		const Scenes pauseMenuChangeScene = Scenes::GAMEPLAY;		
		const Scenes restartGameplayScene = Scenes::GAMEPLAY;
		const Scenes mainMenuRestartGameplayScene = Scenes::MAIN_MENU;

		const MouseButton pauseMenuInputButton = MouseButton::MOUSE_BUTTON_LEFT;

		const Color versionTextColor = WHITE;		

		Vector2 versionTextPosition;
		Vector2 resolution;

		Scenes mainMenuChangeScenes[maxMainMenuButtons];
		Scenes pauseMenuChangeScenes[maxMainMenuButtons];

		int screenWidth;
		int screenHeight;
		int versionTextSize;

		SceneManager* sceneManager;
		Gameplay* gameplay;
		MainMenu* mainMenu;
		Credits* credits;
		Upgrader* upgrader;
		Tutorial* tutorial;
		EndGame* endGame;
		PauseMenu* pauseMenu;
		OptionsMenu* optionsMenu;

		bool running;
	public:
		Game();
		~Game();

		void setScreenWidth(int screenWidth);
		void setScreenHeight(int screenHeight);		
		void setMainMenuChangeScenes();
		void setPauseMenuChangeScenes();
		void setVersionTextSize();
		void setversionTextPosition(Vector2 versionTextPosition);
		void setResolution(Vector2 resolution);
		void setRunning(bool running);
				
		int getScreenWidth();
		int getScreenHeight();
		Vector2 getversionTextPosition();
		Vector2 getResolution();
		int getVersionTextSize();
		bool getRunning();

		void init();		
		void deinit();

		void drawVersion();

		void runGame();
		void temporalUnuseScenes();			

		void resolutionUpdate();
		bool resolutionChanged();
		void setWindowPosition();
	};
}

#endif
