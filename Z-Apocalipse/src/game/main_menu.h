#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "button.h"
#include "..\gameplay\scene_manager.h"

namespace Z_APOCALIPSE 
{
	const short maxMainMenuButtons = 4;

	class MainMenu
	{
	private:		
		const float widthPercentage = 0.2f;
		const float heightPercentage = 0.1f;
		const float separationPercentage = 0.05f;
		const float tittlePercentage = 0.2f;
		const Color backgroundColor = WHITE;
		const Color buttonColorOne = BLUE;
		const Color buttonColorTwo = RED;
		const Color titleTextColor = BLACK;
		const char* titleText = "Z-APOCALIPSE";
		const short titleTextSize = 60;

		Button* button[maxMainMenuButtons];	
	public:
		MainMenu(const char* texts[maxMainMenuButtons]);
		~MainMenu();		
				
		void input(SceneManager* sceneManager, Scenes newScene[maxMainMenuButtons]);	
		void draw();

		void createButtons(const char* texts[maxMainMenuButtons]);
	};
}

#endif