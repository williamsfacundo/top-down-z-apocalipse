#ifndef GAME_H
#define GAME_H

#include "scene_manager.h"

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
	public:
		Game(int screenWidth, int screenHeight);
		~Game();

		void setScreenWidth(int screenWidth);
		void setScreenHeight(int screenHeight);

		void init();
		void input();
		void update();
		void draw();
		void deinit();

		void runGame();
	};
}

#endif
