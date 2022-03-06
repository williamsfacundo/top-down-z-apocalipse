#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <raylib.h>

#include "button.h"
#include "..\gameplay\scene_manager.h"

namespace Z_APOCALIPSE 
{
	const short maxMainMenuButtons = 4;

	class MainMenu
	{
	private:		
		const float buttonsYPercentage = 0.2f;
		const float buttonsWidthPercentage = 0.3f;
		const float buttonsHeightPercentage = 0.1f;
		const float separationPercentage = 0.05f;
		const float tittleYPercentage = 0.1f;
		const float titleSizeDivider = 20.0f;

		const Color backgroundColor = BLACK;
		const Color buttonColorOne = YELLOW;
		const Color buttonColorTwo = RED;
		const Color titleTextColor = GRAY;

		const char* titleText = "Z-APOCALIPSE";		

		const short titleAmountOfLetters = 12;

		int titleTextSize;

		Vector2 titlePosition;

		Button* button[maxMainMenuButtons];	
	public:
		MainMenu(const char* texts[maxMainMenuButtons]);
		~MainMenu();		

		void setTitleTextSize(short titleTextSize);
		void setTitlePosition();

		short getTitleTextSize();
		Vector2 getTitlePosition();
				
		void input(SceneManager* sceneManager, Scenes newScene[maxMainMenuButtons]);	
		
		void draw();
		void drawTitle();
		void drawButtons();

		void createButtons(const char* texts[maxMainMenuButtons]);
	};
}

#endif