#ifndef GAME_H
#define GAME_H

#include "scene_manager.h"
#include "gameplay.h"
#include "..\game\main_menu.h"

namespace Z_APOCALIPSE 
{
	class Game
	{
	private:
		int screenWidth;
		int screenHeight;
		const char* title = "Z-APOCALIPSE";
		const char* mainMenuTexts[maxMainMenuButtons] = { "PLAY", "OPTIONS", "CREDITS", "EXIT" };
		const short fps = 60;
		const Scenes initialScene = Scenes::MAIN_MENU;	
				
		Scenes mainMenuChangeScenes[maxMainMenuButtons];
		SceneManager* sceneManager;
		Gameplay* gameplay;
		MainMenu* mainMenu;
		bool running;
	public:
		Game(int screenWidth, int screenHeight);
		~Game();

		void setScreenWidth(int screenWidth);
		void setScreenHeight(int screenHeight);
		void setMainMenuChangeScenes();
		void setRunning(bool running);

		bool getRunning();

		void init();		
		void deinit();

		void runGame();
		void temporalUnuseScenes();
	};
}

#endif
