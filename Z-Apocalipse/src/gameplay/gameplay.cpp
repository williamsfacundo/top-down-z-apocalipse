#include "gameplay.h"

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	Gameplay::Gameplay()
	{
		init();

		updateHudSpace();
	}

	Gameplay::~Gameplay() 
	{
		deinit();
	}

	void Gameplay::init()
	{
		playerOne = new Survivor(playerOneColor, {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, playerOneRadius);
	}
	
	void Gameplay::input() 
	{
		playerOne->input();
	}
	
	void Gameplay::update() 
	{
		playerOne->update({ gameplaySpacePos.x, gameplaySpacePos.y, static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight });
	}
	
	void Gameplay::draw() 
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		drawHudSpace();

		playerOne->draw();	

		EndDrawing();
	}
	
	void Gameplay::deinit() 
	{
		delete playerOne;
	}

	void Gameplay::drawHudSpace() 
	{
		DrawRectangleV(gameplaySpacePos, {static_cast<float>(GetScreenWidth()) , gameplaySpaceHeight}, gameplaySpaceColor);
	}

	void Gameplay::updateHudSpace()
	{
		gameplaySpaceHeight = GetScreenHeight() - (GetScreenHeight() * hudHeightPercentage);
		gameplaySpacePos.y = GetScreenHeight() * (hudHeightPercentage / 2.0f);
	}
}