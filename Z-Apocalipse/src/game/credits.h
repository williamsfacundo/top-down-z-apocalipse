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
		const Color backgroundColor = WHITE;
		const Color buttonColorOne = BLUE;
		const Color buttonColorTwo = RED;
		const Color creditsColor = BLACK;
		const Scenes goBackScene = Scenes::MAIN_MENU;
		const char* buttonText = "MENU";
		const char* developerNameText = "Game Dev: WILLIAMS FACUNDO";
		const float buttonSize = 200.0f;
		const int creditsFontSize = 30;
		
		Rectangle buttonShape;
		Button* button;
	public:
		Credits();
		~Credits();

		void setButtonShape(float x, float y, float width, float height);

		Rectangle getButtonShape();

		void input(SceneManager* sceneManager);
		void draw(MainMenu* mainMenu);
		void drawDevName();
	};
}

#endif