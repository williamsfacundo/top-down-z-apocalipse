#include "gameplay/game.h"

using namespace Z_APOCALIPSE;

void main() 
{
	Game* game = new Game(800, 450);

	game->runGame();

	delete game;
}