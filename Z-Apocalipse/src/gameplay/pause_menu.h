#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include <raylib.h>

#include "..\game\button.h";
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	class PauseMenu
	{
	private:		
		static const short maxButtons = 4;

		const Color buttonsColorOne = YELLOW;
		const Color buttonsColorTwo = RED;
		const Color backgroundColor = BLACK;
		const Color titleColor = RED;
				
		const float titleTextYPercentage = 0.1f;
		const float buttonsYPercentage = 0.3f;		
		const float buttonsWidthPercentage = 0.2f;
		const float buttonsHeightPercentage = 0.1f;
		const float buttonsHeightSeparationPercentage = 1.0f;

		const char* buttonsText[maxButtons] = { "RESUME", "RESTART", "OPTIONS", "MENU" };
		const char* titleText = "PAUSE MENU";

		const short titleSize = 60;
		
		int titleTextXPos;
		int titleTextYPos;

		Scenes changeScenes[maxButtons];

		Button* buttons[maxButtons];
	public:
		PauseMenu(Scenes changeScenes[maxButtons]);
		~PauseMenu();

		void setTitleTextXPos(int titleTextXPos);
		void setTitleTextYPos(int titleTextYPos);
		void setChangeScenes(Scenes changeScenes[maxButtons]);

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
