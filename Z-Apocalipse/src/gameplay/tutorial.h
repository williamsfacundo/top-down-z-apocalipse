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
		const Color buttonColorOne = RED;
		const Color buttonColorTwo = YELLOW;
		const float buttonWidthPercentage = 0.2f;
		const float buttonHeightPercentage = 0.1f;
		const float buttonYPercentage = 0.8f;
		const char* buttonText = "START";

		Button* goToGameplayButton;		
	public:
		Tutorial();
		~Tutorial();

		void input(SceneManager* sceneManager);
		void draw();
	};
}

#endif
