#ifndef SURVIVOR_H
#define SURVIVOR_H

#include "character.h"

namespace Z_APOCALIPSE 
{
	class Survivor : public Character
	{
	private:
		const short initialLives = 3;
		const short initialMoney = 200;
		short lives;
		short money;
	public:
		Survivor(Vector2 position, float radius);

		void setLives(short lives);
		void setMoney(short money);
		short getLives();
		short getMoney();

		void input();
		virtual void update();
	};
}

#endif
