#include "end_game.h"

#include <raylib.h>

#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	EndGame::EndGame() 
	{
		goMenuButton = new Button({ static_cast<float>(GetScreenWidth() * goMenuButtonXPercentage),
			static_cast<float>(GetScreenHeight() * goMenuButtonYPercentage), static_cast<float>(GetScreenWidth() * goMenuButtonWidthPercentage),
			static_cast<float>(GetScreenHeight() * goMenuButtonHeightPercentage) },buttonsColorOne, buttonsColorTwo, goMenuButtonText);
	}

	EndGame::~EndGame() 
	{
		delete goMenuButton;
	}

	void EndGame::input(SceneManager* sceneManager) 
	{
		goMenuButton->changeSceneWhenButtonPress(sceneManager, menuScene);
	}

	void EndGame::draw() 
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		goMenuButton->draw();

		EndDrawing();
	}
}