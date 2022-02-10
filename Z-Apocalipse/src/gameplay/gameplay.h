#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "survivor.h"

#include <raylib.h>

namespace Z_APOCALIPSE
{
	class Gameplay
	{
	private:
		const Color backgroundColor = GRAY;
		const Color gameplaySpaceColor = BLACK;
		const float hudHeightPercentage = 0.36f;
		Vector2 gameplaySpacePos;
		float gameplaySpaceHeight;
		
		const float playerOneRadius = 30.0f;
		const Color playerOneColor = YELLOW;
		Survivor* playerOne;
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
	};
}

#endif
