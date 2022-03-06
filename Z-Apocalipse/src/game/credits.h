#ifndef CREDITS_H
#define CREDITS_H

#include <raylib.h>

#include "button.h"
#include "main_menu.h"

namespace Z_APOCALIPSE 
{
	class Credits
	{
	private:
		const Color backgroundColor = BLACK;
		const Color buttonColorOne = YELLOW;
		const Color buttonColorTwo = RED;
		const Color creditsColor = WHITE;
		const Color developerTextColor = WHITE;

		const Scenes goBackScene = Scenes::MAIN_MENU;
		
		const char* buttonText = "MENU";
		const char* developerNameText = "Game Dev: WILLIAMS FACUNDO";
		const char* toolsText = "TOOLS USED: visual studio and raylib library";
		
		const short developerNameTextAmountOfLetters = 26;
				
		const float buttonYPercentage = 0.8f;
		const float buttonWidthPercentage = 0.3f;
		const float buttonHeightPercentage = 0.1f;	
		const float creditsTextYPercentage = 0.3f;
		const float creditsFontSizeDivider = 38.0f;
		const float creditsSeparationPercentage = 0.12f;

		int creditsFontSize;
		
		Rectangle buttonShape;

		Vector2 creditsTextsPosition;
		
		Button* button;
	public:
		Credits();
		~Credits();

		void setCreditsFontSize();
		void setButton();
		void setButtonShape(float x, float y, float width, float height);
		void setCreditsTextsPosition();

		int getCreditsFontSize();
		Rectangle getButtonShape();
		Vector2 getCreditsTextsPosition();
		
		void input(SceneManager* sceneManager);
		void draw(MainMenu* mainMenu);
		void drawDevName();
		void drawToolsText();
	};
}

#endif