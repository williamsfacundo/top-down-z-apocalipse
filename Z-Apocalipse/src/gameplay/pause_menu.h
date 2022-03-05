#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include <raylib.h>

#include "..\game\button.h";
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	const short maxPauseMenuButtons = 4;

	class PauseMenu
	{
	private:
		const Color buttonsColorOne = YELLOW;
		const Color buttonsColorTwo = RED;
		const Color backgroundColor = WHITE;
		const Color titleColor = BLACK;
				
		const float titleTextYPercentage = 0.05f;
		const float buttonsYPercentage = 0.2f;		
		const float buttonsWidthPercentage = 0.25f;
		const float buttonsHeightPercentage = 0.12f;
		const float buttonsHeightSeparationPercentage = 0.2f;

		const char* buttonsText[maxPauseMenuButtons] = { "RESUME", "RESTART", "OPTIONS", "MENU" };
		const char* titleText = "PAUSE MENU";

		const short titleSize = 60;
		const short titleAmountLetters = 10;
		
		int titleTextXPos;
		int titleTextYPos;

		Scenes changeScenes[maxPauseMenuButtons];

		Button* buttons[maxPauseMenuButtons];
	public:
		PauseMenu(Scenes changeScenes[maxPauseMenuButtons]);
		~PauseMenu();

		void setTitleTextXPos(int titleTextXPos);
		void setTitleTextYPos(int titleTextYPos);
		void setChangeScenes(Scenes changeScenes[maxPauseMenuButtons]);
		void setButtons();

		int getTitleTextXPos();
		int getTitleTextYPos();
		Scenes getChangeScene(short index);

		void input(SceneManager* sceneManager);
		void draw();

		void drawTitle();
		void drawButtons();
	};
}

#endif
