#ifndef GAME_H
#define GAME_H

#include "scene_manager.h"
#include "gameplay.h"

namespace Z_APOCALIPSE 
{
	class Game
	{
	private:
		int screenWidth;
		int screenHeight;
		const char* title = "Z-APOCALIPSE";
		const short fps = 60;
		
		SceneManager* sceneManager;
		Gameplay* gameplay;
	public:
		Game(int screenWidth, int screenHeight);
		~Game();

		void setScreenWidth(int screenWidth);
		void setScreenHeight(int screenHeight);

		void init();		
		void deinit();

		void runGame();
	};
}

#endif
