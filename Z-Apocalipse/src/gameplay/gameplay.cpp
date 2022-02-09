#include "gameplay.h"

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	Gameplay::Gameplay() 
	{

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

		DrawText("Z-APOCALIPSE", 190, 200, 20, RED);

		EndDrawing();
	}
	
	void Gameplay::deinit() 
	{

	}
}