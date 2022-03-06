#ifndef END_GAME_H
#define END_GAME_H

#include <raylib.h>

#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	class EndGame
	{
	private:
		Scenes menuScene = Scenes::MAIN_MENU;
		Scenes gameplayScene = Scenes::GAMEPLAY;

		const Color titleColor = GRAY;
		const Color backgroundColor = BLACK;
		const Color buttonsColorOne = YELLOW;
		const Color buttonsColorTwo = RED;
		const Color scoreTextColor = WHITE; 

		const float titleYPercentage = 0.18f;		
		const float scoreTextYPercentage = 0.45;		
		const float goMenuButtonXPercentage = 0.1f;
		const float restartButtonXPercentage = 0.7f;
		const float buttonsWidthPercentage = 0.2f;
		const float buttonsHeightPercentage = 0.1f;
		const float buttonsYPercentage = 0.8f;
		const float titleSizeDivider = 10.0f;
		const float scoreSizeDivider = 15.0f;

		const short zombiesKilledMultiplyer = 85;
		const short timeSurvivedMultiplyer = 15;
		const short titleAmountLetters = 8;
		const short scoreTextAmountLetters = 6;

		const char* titleText = "END GAME";
		const char* goMenuButtonText = "GO MENU";
		const char* restartButtonText = "RESTART";
		const char* scoreText = "SCORE %i";

		int titleSize;
		int scoreSize;
		int score;

		Vector2 titleSizePosition;
		Vector2 scoreSizePosition;

		Button* goMenuButton;
		Button* restartButton;
	public:
		EndGame();
		~EndGame();

		void setTitleSize();
		void setScoreSize();
		void setScore(int score);
		void setTitleSizePosition();
		void setScoreSizePosition();

		int getTitleSize();
		int getScoreSize();
		int getScore();
		Vector2 getTitleSizePosition();
		Vector2 getScoreSizePosition();

		void input(SceneManager* sceneManager);
		void draw();

		void drawTitle();	
		void drawScore();

		void calculateScore(int zombiesKilled, int timeSurvived);
	};
}

#endif
