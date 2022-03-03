#ifndef GAME_H
#define GAME_H

#include "scene_manager.h"
#include "gameplay.h"
#include "..\game\main_menu.h"
#include "..\game\credits.h"
#include "..\gameplay\upgrader.h"

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
		const Scenes initialScene = Scenes::UPGRADER; 	
		const Scenes pauseMenuChangeScene = Scenes::GAMEPLAY; 
		const MouseButton pauseMenuInputButton = MouseButton::MOUSE_BUTTON_LEFT;
				
		Scenes mainMenuChangeScenes[maxMainMenuButtons];
		SceneManager* sceneManager;
		Gameplay* gameplay;
		MainMenu* mainMenu;
		Credits* credits;
		Upgrader* upgrader;

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

		void pauseInput(Vector2 pauseCirclePosition,float pauseCircleRadius);
	};
}

#endif
