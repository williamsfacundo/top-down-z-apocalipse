#include "tutorial.h"

#include <raylib.h>

#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	Tutorial::Tutorial() 
	{
		goToGameplayButton = new Button( { static_cast<float>(GetScreenWidth() / 2 - (GetScreenWidth() * buttonWidthPercentage / 2.0f)), 
			static_cast<float>(GetScreenHeight() * buttonYPercentage), static_cast<float>(GetScreenWidth()* buttonWidthPercentage), 
			static_cast<float>(GetScreenHeight() * buttonHeightPercentage)}, buttonColorOne, buttonColorTwo, buttonText );
	}

	Tutorial::~Tutorial() 
	{
		delete goToGameplayButton;
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

		EndDrawing();
	}
}