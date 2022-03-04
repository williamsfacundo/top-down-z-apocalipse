#ifndef END_GAME_H
#define END_GAME_H

#include <raylib.h>

#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	class EndGame
	{
	private:
		Scenes menuScene = Scenes::MAIN_MENU;
		Scenes gameplayScene = Scenes::GAMEPLAY;

		const Color backgroundColor = BLACK;
		const Color buttonsColorOne = YELLOW;
		const Color buttonsColorTwo = RED;

		const float goMenuButtonXPercentage = 0.2f;
		const float goMenuButtonWidthPercentage = 0.2f;
		const float goMenuButtonHeightPercentage = 0.1f;
		const float goMenuButtonYPercentage = 0.9f;

		const char* goMenuButtonText = "GO MENU";

		Button* goMenuButton;
	public:
		EndGame();
		~EndGame();

		void input(SceneManager* sceneManager);
		void draw();
	};
}

#endif
