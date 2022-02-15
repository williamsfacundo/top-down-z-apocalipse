#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "survivor.h"
#include "zombie.h"

#include <raylib.h>

namespace Z_APOCALIPSE
{
	class Gameplay
	{
	private:
		const Color backgroundColor = LIGHTGRAY;
		const Color gameplaySpaceColor = GRAY;
		const Color playerOneColor = RED;
		const Color zombiesColor = GREEN;
		const float hudHeightPercentage = 0.36f;		
		const float playerOneRadius = 30.0f;
		const float zombiesRadius = 22.5f;
		static const short maxZombies = 1;

		Vector2 gameplaySpacePos;
		float gameplaySpaceHeight;		
		
		Survivor* playerOne;
		Zombie* zombies[maxZombies];
	public:
		Gameplay();
		~Gameplay();

		void init();
		void input();
		void update();
		void draw();
		void deinit();

		void drawHudSpace();
		void updateHudSpace();
		void drawZombies();
	};
}

#endif
