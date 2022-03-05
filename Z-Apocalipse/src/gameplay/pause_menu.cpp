#include "pause_menu.h"

#include <raylib.h>

#include "..\game\button.h";
#include "scene_manager.h"

namespace Z_APOCALIPSE
{
	PauseMenu::PauseMenu(Scenes changeScenes[maxButtons])
	{
		setChangeScenes(changeScenes);

		float buttonsHeight = static_cast<float>(GetScreenHeight() * buttonsYPercentage);

		for (short i = 0; i < maxButtons; i++) 
		{
			buttons[i] = new Button({ static_cast<float>((GetScreenWidth() / 2) - (buttonsHeight / 2.0f)), 
				buttonsHeight + (GetScreenHeight() * buttonsHeightSeparationPercentage * i), 
				static_cast<float>(GetScreenWidth() * buttonsWidthPercentage), 
				buttonsHeight }, 
				buttonsColorOne, buttonsColorTwo, buttonsText[i]);
		}
	}

	PauseMenu::~PauseMenu()
	{
		for (short i = 0; i < maxButtons; i++)
		{
			delete buttons[i];
			buttons[i] = NULL;
		}
	}

	void PauseMenu::setTitleTextXPos(int titleTextXPos) 
	{
		this->titleTextXPos = titleTextXPos;
	}

	void PauseMenu::setTitleTextYPos(int titleTextYPos) 
	{
		this->titleTextYPos = titleTextYPos;
	}

	void PauseMenu::setChangeScenes(Scenes changeScenes[maxButtons]) 
	{
		for (short i = 0; i < maxButtons; i++) 
		{
			this->changeScenes[i] = changeScenes[i];
		}
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
		for (short i = 0; i < maxButtons; i++) 
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
		DrawText(titleText, getTitleTextXPos(), getTitleTextYPos(), titleSize, titleColor);
	}

	void PauseMenu::drawButtons()
	{
		for (short i = 0; i < maxButtons; i++)
		{
			buttons[i]->draw();
		}
	}
}