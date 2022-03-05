#include "end_game.h"

#include <raylib.h>

#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	EndGame::EndGame() 
	{
		goMenuButton = new Button({ static_cast<float>(GetScreenWidth() * goMenuButtonXPercentage),
			static_cast<float>(GetScreenHeight() * buttonsYPercentage), static_cast<float>(GetScreenWidth() * buttonsWidthPercentage),
			static_cast<float>(GetScreenHeight() * buttonsHeightPercentage) },buttonsColorOne, buttonsColorTwo, goMenuButtonText);
		
		restartButton = new Button({ static_cast<float>(GetScreenWidth() * restartButtonXPercentage),
			static_cast<float>(GetScreenHeight() * buttonsYPercentage), static_cast<float>(GetScreenWidth() * buttonsWidthPercentage),
			static_cast<float>(GetScreenHeight() * buttonsHeightPercentage) }, buttonsColorOne, buttonsColorTwo, restartButtonText);

		setScore(0);
	}

	EndGame::~EndGame() 
	{
		delete goMenuButton;
		delete restartButton;
	}

	void EndGame::setScore(int score)
	{
		this->score = score;
	}

	int EndGame::getScore()
	{
		return score;
	}

	void EndGame::input(SceneManager* sceneManager) 
	{
		goMenuButton->changeSceneWhenButtonPress(sceneManager, menuScene);

		restartButton->changeSceneWhenButtonPress(sceneManager, gameplayScene);
	}

	void EndGame::draw() 
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		goMenuButton->draw();

		restartButton->draw();

		drawTitle();

		EndDrawing();
	}

	void EndGame::drawTitle() 
	{
		DrawText(titleText, static_cast<int>(GetScreenWidth() * titleXPercentage),
			static_cast<int>(GetScreenHeight() * titleYPercentage), titleSize, titleColor);
	}	

	void EndGame::calculateScore(int zombiesKilled, int timeSurvived) 
	{
		setScore((zombiesKilled * zombiesKilledMultiplyer) + (timeSurvived * timeSurvivedMultiplyer));
	}
}