#include "pause_menu.h"

#include <raylib.h>

#include "..\math\math.h"
#include "..\game\button.h";
#include "scene_manager.h"

namespace Z_APOCALIPSE
{
	PauseMenu::PauseMenu(Scenes changeScenes[maxPauseMenuButtons])
	{
		setTitleTextSize(vectorMath::getScreenHypotenuse() / titleSizeDivider);

		setTitleTextXPos(static_cast<int>((GetScreenWidth() / 2) - ((titleAmountLetters / 3) * titleSize)));

		setTitleTextYPos(static_cast<int>(GetScreenHeight() * titleTextYPercentage));

		setChangeScenes(changeScenes);

		setButtons();	
	}

	PauseMenu::~PauseMenu()
	{
		for (short i = 0; i < maxPauseMenuButtons; i++)
		{
			delete buttons[i];
			buttons[i] = NULL;
		}
	}

	void PauseMenu::setTitleTextSize(int titleSize)
	{
		this->titleSize = titleSize;
	}

	void PauseMenu::setTitleTextXPos(int titleTextXPos) 
	{
		this->titleTextXPos = titleTextXPos;
	}

	void PauseMenu::setTitleTextYPos(int titleTextYPos) 
	{
		this->titleTextYPos = titleTextYPos;
	}

	void PauseMenu::setChangeScenes(Scenes changeScenes[maxPauseMenuButtons]) 
	{
		for (short i = 0; i < maxPauseMenuButtons; i++) 
		{
			this->changeScenes[i] = changeScenes[i];
		}
	}

	void PauseMenu::setButtons()
	{		
		float width = static_cast<float>(GetScreenWidth() * buttonsWidthPercentage);
		float height = static_cast<float>(GetScreenHeight() * buttonsHeightPercentage);
		float xPos = static_cast<float>((GetScreenWidth() / 2) - (width / 2.0f));
		float yPos = static_cast<float>(GetScreenHeight() * buttonsYPercentage);
		float separation = static_cast<float>(GetScreenHeight() * buttonsHeightSeparationPercentage);

		for (short i = 0; i < maxPauseMenuButtons; i++)
		{
			buttons[i] = new Button({ xPos,	yPos + (separation * i) + (height * i), width,	height },
				buttonsColorOne, buttonsColorTwo, buttonsText[i]);
		}
	}

	int PauseMenu::getTitleTextSize()
	{
		return titleSize;
	}

	int PauseMenu::getTitleTextXPos()
	{
		return titleTextXPos;
	}

	int	PauseMenu::getTitleTextYPos()
	{
		return titleTextYPos;
	}

	Scenes PauseMenu::getChangeScene(short index) 
	{
		return changeScenes[index];
	}

	void PauseMenu::input(SceneManager* sceneManager)
	{
		for (short i = 0; i < maxPauseMenuButtons; i++) 
		{
			buttons[i]->changeSceneWhenButtonPress(sceneManager, getChangeScene(i));
		}
	}
	
	void PauseMenu::draw() 
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		drawTitle();

		drawButtons();
	}

	void PauseMenu::drawTitle() 
	{
		DrawText(titleText, getTitleTextXPos(), getTitleTextYPos(), getTitleTextSize(), titleColor);
	}

	void PauseMenu::drawButtons()
	{
		for (short i = 0; i < maxPauseMenuButtons; i++)
		{
			buttons[i]->draw();
		}
	}
}