#include "gameplay/game.h"

void main() 
{
	Game* game = new Game(800, 450);

	game->runGame();

	delete game;
}