#include "tutorial.h"

#include <raylib.h>

#include "..\math\math.h"
#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	Tutorial::Tutorial() 
	{
		setTitleTextSize();
		setTutorialTextsSize();

		goToGameplayButton = new Button( { static_cast<float>(GetScreenWidth() / 2 - (GetScreenWidth() * buttonWidthPercentage / 2.0f)), 
			static_cast<float>(GetScreenHeight() * buttonYPercentage), static_cast<float>(GetScreenWidth()* buttonWidthPercentage), 
			static_cast<float>(GetScreenHeight() * buttonHeightPercentage)}, buttonColorOne, buttonColorTwo, buttonText );
	}

	Tutorial::~Tutorial() 
	{
		delete goToGameplayButton;
	}

	void Tutorial::setTitleTextSize()
	{
		titleTextSize = vectorMath::getScreenHypotenuse() / titleSizeDivider;
	}

	void Tutorial::setTutorialTextsSize()
	{
		tutorialTextsSize = vectorMath::getScreenHypotenuse() / tutorialTextSizeDivider;
	}

	int Tutorial::getTitleTextSize()
	{
		return titleTextSize;
	}

	int Tutorial::getTutorialTextsSize()
	{
		return tutorialTextsSize;
	}
		
	void Tutorial::input(SceneManager* sceneManager)
	{
		goToGameplayButton->changeSceneWhenButtonPress(sceneManager, gameplayScene);
	}

	void Tutorial::draw() 
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		goToGameplayButton->draw();
		drawTitle();
		drawTutorialTexts();

		EndDrawing();
	}

	void Tutorial::drawTitle() 
	{
		DrawText(titleText, (GetScreenWidth() / 2) - (getTitleTextSize() * (titleTextAmountOfLetters / 2)), static_cast<int>(GetScreenHeight() * titleTextYPercentage), getTitleTextSize(), titleTextColor);
	}

	void Tutorial::drawTutorialTexts() 
	{
		for (short i = 0; i < maxTutorialTexts; i++)
		{
			DrawText(tutorialTexts[i], static_cast<int>(GetScreenWidth() * tutorialTextsXPercentage), 
				static_cast<int>((GetScreenHeight() * tutorialTextsInitialYPercentage) + (GetScreenHeight() * tutorialTextsSeparation * (i + 1))),
				getTutorialTextsSize(), tutorialTextsColor);
		}
	}
}