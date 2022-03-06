#include "end_game.h"

#include <iostream>
#include <raylib.h>

#include "..\game\button.h"
#include "scene_manager.h"
#include "..\math\math.h"

namespace Z_APOCALIPSE 
{
	EndGame::EndGame() 
	{
		setTitleSize();
		setScoreSize();
		setScore(0);
		setTitleSizePosition();
		setScoreSizePosition();

		goMenuButton = new Button({ static_cast<float>(GetScreenWidth() * goMenuButtonXPercentage),
			static_cast<float>(GetScreenHeight() * buttonsYPercentage), static_cast<float>(GetScreenWidth() * buttonsWidthPercentage),
			static_cast<float>(GetScreenHeight() * buttonsHeightPercentage) },buttonsColorOne, buttonsColorTwo, goMenuButtonText);
		
		restartButton = new Button({ static_cast<float>(GetScreenWidth() * restartButtonXPercentage),
			static_cast<float>(GetScreenHeight() * buttonsYPercentage), static_cast<float>(GetScreenWidth() * buttonsWidthPercentage),
			static_cast<float>(GetScreenHeight() * buttonsHeightPercentage) }, buttonsColorOne, buttonsColorTwo, restartButtonText);		
	}

	EndGame::~EndGame() 
	{
		delete goMenuButton;
		delete restartButton;
	}

	void EndGame::setTitleSize() 
	{
		titleSize = vectorMath::getScreenHypotenuse() / titleSizeDivider;
	}

	void EndGame::setScoreSize() 
	{
		scoreSize = vectorMath::getScreenHypotenuse() / scoreSizeDivider;
	}

	void EndGame::setScore(int score)
	{
		this->score = score;
	}

	void EndGame::setTitleSizePosition() 
	{
		titleSizePosition = { static_cast<float>((GetScreenWidth() / 2) - ((titleAmountLetters / 3) * titleSize)),
			static_cast<float>(GetScreenHeight() * titleYPercentage) };
	}

	void EndGame::setScoreSizePosition() 
	{
		scoreSizePosition = { static_cast<float>((GetScreenWidth() / 2) - ((scoreTextAmountLetters / 3) * scoreSize)),
			static_cast<float>(GetScreenHeight() * scoreTextYPercentage) };
	}

	int EndGame::getTitleSize() 
	{
		return titleSize;
	}

	int EndGame::getScoreSize() 
	{
		return scoreSize;
	}

	int EndGame::getScore()
	{
		return score;
	}

	Vector2 EndGame::getTitleSizePosition() 
	{
		return titleSizePosition;
	}

	Vector2 EndGame::getScoreSizePosition() 
	{
		return scoreSizePosition;
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
		
		drawScore();

		EndDrawing();		
	}

	void EndGame::drawTitle() 
	{
		DrawText(titleText, static_cast<int>(getTitleSizePosition().x),	static_cast<int>(getTitleSizePosition().y), 
			getTitleSize(), titleColor);
	}	

	void EndGame::drawScore() 
	{
		DrawText(TextFormat(scoreText, getScore()), static_cast<int>(getScoreSizePosition().x),	static_cast<int>(getScoreSizePosition().y), 
			getScoreSize(), scoreTextColor);
	}

	void EndGame::calculateScore(int zombiesKilled, int timeSurvived) 
	{
		setScore((zombiesKilled * zombiesKilledMultiplyer) + (timeSurvived * timeSurvivedMultiplyer));
	}
}