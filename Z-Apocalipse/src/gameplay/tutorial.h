#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <raylib.h>

#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	class Tutorial
	{
	private:
		const Scenes gameplayScene = Scenes::GAMEPLAY;

		const Color backgroundColor = BLACK;
		const Color titleTextColor = RED;
		const Color buttonColorOne = YELLOW;
		const Color buttonColorTwo = RED;
		const Color tutorialTextsColor = WHITE;

		const float buttonWidthPercentage = 0.2f;
		const float buttonHeightPercentage = 0.1f;
		const float buttonYPercentage = 0.9f;
		const float titleTextYPercentage = 0.1f;
		const float tutorialTextsXPercentage = 0.05f;
		const float tutorialTextsInitialYPercentage = 0.18f;
		const float tutorialTextsSeparation = 0.08f;	

		const int titleTextSize = 40;
		const int tutorialTextsSize = 16;

		const short titleTextAmountOfLetters = 8;
		static const short maxTutorialTexts = 8;

		const char* buttonText = "START";
		const char* titleText = "TUTORIAL";

		const char* tutorialTexts[maxTutorialTexts] = { 
			"MOVE CHARACTER: W-A-S-D (KEYS)", 
			"AIM WITH MOUSE AND LEFT CLICK TO SHOOT (R KEY TO RELOAD)", 
			"PLAYER CAN PICK UP AMMUNITION FROM THE FLOOR",
			"SURVIVE ZOMBIES WAVES (X AMOUNT OF TIME PER ROUND), KILLING AS MUCH AS YOU CAN",
			"EVERY KILL GIVES THE PLAYER MONEY TO SPEND AT THE UPGRADE MENU",
			"UPGRADE MENU WILL BE AVAILABLE AT THE END OF EACH ROUND",
			"IF A ZOMBIE TOUCHES PLAYER LOSES A LIFE, WHEN THEY REACH ZERO GAME IS OVER",			
			"ROUNDS ARE INFINITE, AND EACH ONES IS MORE DIFFICULT THAN THE PREVIOUS ONE"};

		Button* goToGameplayButton;		
	public:
		Tutorial();
		~Tutorial();

		void input(SceneManager* sceneManager);
		void draw();
		void drawTitle();
		void drawTutorialTexts();
	};
}

#endif
