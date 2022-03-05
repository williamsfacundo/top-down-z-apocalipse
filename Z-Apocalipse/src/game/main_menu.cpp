#include "main_menu.h"

#include <raylib.h>

#include "button.h"
#include "..\gameplay\scene_manager.h"

#include "..\math\math.h"

namespace Z_APOCALIPSE 
{
	MainMenu::MainMenu(const char* texts[maxMainMenuButtons])
	{
		setTitleTextSize(vectorMath::getScreenHypotenuse() / titleSizeDivider);

		setTitlePosition();

		createButtons(texts);
	}

	MainMenu::~MainMenu()
	{
		for (short i = 0; i < maxMainMenuButtons; i++)
		{
			delete button[i];
		}
	}

	void MainMenu::setTitleTextSize(short titleTextSize)
	{
		this->titleTextSize = titleTextSize;
	}

	void MainMenu::setTitlePosition()
	{
		titlePosition = { static_cast<float>((GetScreenWidth() / 2) - ((titleAmountOfLetters / 3) * titleTextSize)),
			static_cast<float>(GetScreenHeight() * tittleYPercentage) };
	}

	short MainMenu::getTitleTextSize() 
	{
		return titleTextSize;
	}

	Vector2 MainMenu::getTitlePosition() 
	{
		return titlePosition;
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

		drawButtons();		
	}

	void MainMenu::drawTitle()
	{
		DrawText(titleText, static_cast<int>(getTitlePosition().x), static_cast<int>(getTitlePosition().y), titleTextSize, titleTextColor);
	}

	void MainMenu::drawButtons()
	{
		for (short i = 0; i < maxMainMenuButtons; i++)
		{
			button[i]->draw();
		}
	}

	void MainMenu::createButtons(const char* texts[maxMainMenuButtons])
	{
		float width = static_cast<float>(GetScreenWidth() * buttonsWidthPercentage);
		float height = static_cast<float>(GetScreenHeight() * buttonsHeightPercentage);
		float xPos = static_cast<float>((GetScreenWidth() / 2) - (width / 2.0f));
		float initialYPos = static_cast<float>(GetScreenWidth() * buttonsYPercentage);
		float separation = static_cast<float>(GetScreenHeight() * separationPercentage);
				
		for (short i = 0; i < maxMainMenuButtons; i++)
		{
			button[i] = new Button( { xPos, initialYPos + (separation * (i)) + (height * i),	
				width, height }, buttonColorOne, buttonColorTwo, texts[i]);
		}
	}
}