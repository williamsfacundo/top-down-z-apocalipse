#include "game/game.h"

#include "math/math.h"

using namespace Z_APOCALIPSE;

void main() 
{	
	Game* game = new Game();

	game->runGame(); 

	delete game;
}