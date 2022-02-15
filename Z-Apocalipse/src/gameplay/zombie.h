#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "character.h"

namespace Z_APOCALIPSE
{
	class Zombie : public Character
	{
	private:
		float damageTaken;
		float damageToDie;
		short level;
	public:
		Zombie(Color characterColor, Vector2 position, float radius, Rectangle gameplayMap, short level);
		~Zombie();

		void setDamageTaken(float damageTaken);
		void setDamageToDie(float damageToDie);
		void setLevel(short level);

		float getDamageTaken();
		float getDamageToDie();
		short getLevel();

		void update(Rectangle gameplayDimensions);
		void movementUpdate();
		void draw();
	};
}

#endif
