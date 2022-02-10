#include "gameplay.h"

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	Gameplay::Gameplay()
	{
		updateHudSpace();
	}

	Gameplay::~Gameplay() 
	{

	}

	void Gameplay::init()
	{

	}
	
	void Gameplay::input() 
	{

	}
	
	void Gameplay::update() 
	{
	
	}
	
	void Gameplay::draw() 
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		drawHudSpace();

		EndDrawing();
	}
	
	void Gameplay::deinit() 
	{

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