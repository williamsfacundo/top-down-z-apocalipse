#ifndef GAME_H
#define GAME_H

#include "scene_manager.h"
#include "gameplay.h"
#include "..\game\main_menu.h"
#include "..\game\credits.h"
#include "..\gameplay\upgrader.h"
#include "..\gameplay\tutorial.h"
#include "..\gameplay\end_game.h"
#include "..\gameplay\pause_menu.h"

namespace Z_APOCALIPSE 
{
	class Game
	{
	private:
		int screenWidth;
		int screenHeight;

		const char* title = "Z-APOCALIPSE";
		const char* mainMenuTexts[maxMainMenuButtons] = { "PLAY", "OPTIONS", "CREDITS", "EXIT" };
		const char* versionText = "v0.4";

		const short versionTextSize = 45;
		const short fps = 60;		

		const Scenes initialScene = Scenes::MAIN_MENU; 	
		const Scenes pauseMenuChangeScene = Scenes::GAMEPLAY;		
		const Scenes restartGameplayScene = Scenes::GAMEPLAY;
		const Scenes mainMenuRestartGameplayScene = Scenes::MAIN_MENU;

		const MouseButton pauseMenuInputButton = MouseButton::MOUSE_BUTTON_LEFT;

		const Color versionTextColor = BLACK;		

		Vector2 versionTextPosition;

		Scenes mainMenuChangeScenes[maxMainMenuButtons];
		Scenes pauseMenuChangeScenes[maxMainMenuButtons];

		SceneManager* sceneManager;
		Gameplay* gameplay;
		MainMenu* mainMenu;
		Credits* credits;
		Upgrader* upgrader;
		Tutorial* tutorial;
		EndGame* endGame;
		PauseMenu* pauseMenu;

		bool running;
	public:
		Game(int screenWidth, int screenHeight);
		~Game();

		void setScreenWidth(int screenWidth);
		void setScreenHeight(int screenHeight);		
		void setMainMenuChangeScenes();
		void setPauseMenuChangeScenes();
		void setversionTextPosition(Vector2 versionTextPosition);
		void setRunning(bool running);
				
		Vector2 getversionTextPosition();
		bool getRunning();

		void init();		
		void deinit();

		void drawVersion();

		void runGame();
		void temporalUnuseScenes();		

		void pauseInput(Vector2 pauseCirclePosition,float pauseCircleRadius);
	};
}

#endif
