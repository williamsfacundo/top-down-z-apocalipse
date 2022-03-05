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

		const Color titleColor = RED;
		const Color backgroundColor = BLACK;
		const Color buttonsColorOne = YELLOW;
		const Color buttonsColorTwo = RED;
		const Color scoreTextColor = GREEN; 

		const float titleYPercentage = 0.22f;
		const float titleXPercentage = 0.26f;
		const float scoreTextYPercentage = 0.45;
		const float scoreTextXPercentage = 0.18;
		const float goMenuButtonXPercentage = 0.1f;
		const float restartButtonXPercentage = 0.7f;
		const float buttonsWidthPercentage = 0.2f;
		const float buttonsHeightPercentage = 0.1f;
		const float buttonsYPercentage = 0.8f;
		
			
		const short titleSize = 70;		
		const short scoreSize = 60;
		const short zombiesKilledMultiplyer = 85;
		const short timeSurvivedMultiplyer = 15;

		const char* titleText = "END GAME";
		const char* goMenuButtonText = "GO MENU";
		const char* restartButtonText = "RESTART";
		const char* scoreText = "SCORE %i";

		int score;

		Button* goMenuButton;
		Button* restartButton;
	public:
		EndGame();
		~EndGame();

		void setScore(int score);

		int getScore();

		void input(SceneManager* sceneManager);
		void draw();

		void drawTitle();	
		void drawScore();

		void calculateScore(int zombiesKilled, int timeSurvived);
	};
}

#endif
