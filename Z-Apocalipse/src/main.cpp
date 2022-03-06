#include "gameplay/game.h"

#include <iostream>

#include "math/math.h"

using namespace Z_APOCALIPSE;

void main() 
{	
	Game* game = new Game(800, 450);

	game->runGame(); 

	delete game;
}