#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <raylib.h>

namespace Z_APOCALIPSE
{
	class Gameplay
	{
	private:
		const Color backgroundColor = WHITE;
	public:
		Gameplay();
		~Gameplay();

		void init();
		void input();
		void update();
		void draw();
		void deinit();
	};
}

#endif
