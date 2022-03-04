#include "main_menu.h"

namespace Z_APOCALIPSE 
{
	MainMenu::MainMenu(const char* texts[maxMainMenuButtons])
	{
		createButtons(texts);
	}

	MainMenu::~MainMenu()
	{
		for (short i = 0; i < maxMainMenuButtons; i++)
		{
			delete button[i];
		}
	}

	void MainMenu::input(SceneManager* sceneManager, Scenes newScene[maxMainMenuButtons])
	{
		for (short i = 0; i < maxMainMenuButtons; i++) 
		{
			button[i]->changeSceneWhenButtonPress(sceneManager, newScene[i]);
		}
	}

	void MainMenu::draw()
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		drawTitle();

		for (short i = 0; i < maxMainMenuButtons; i++) 
		{
			button[i]->draw();	
		}	
	}

	void MainMenu::drawTitle()
	{
		DrawText(titleText, (GetScreenWidth() / 2) - (4 * titleTextSize), static_cast<int>(GetScreenHeight() * (tittlePercentage / 2)), titleTextSize, titleTextColor);
	}

	void MainMenu::createButtons(const char* texts[maxMainMenuButtons])
	{
		float width = GetScreenWidth() * widthPercentage;
		float height = GetScreenHeight() * heightPercentage;
		float initialYPos = GetScreenWidth() * tittlePercentage;
		float separation = GetScreenHeight() * separationPercentage;		
				
		for (short i = 0; i < maxMainMenuButtons; i++)
		{
			button[i] = new Button( { static_cast<float>((GetScreenWidth() / 2) - (width / 2.0f)), 
				initialYPos + (separation * (i + 1.0f)) + (height * i),	width, height }, buttonColorOne, buttonColorTwo, texts[i]);
		}
	}
}