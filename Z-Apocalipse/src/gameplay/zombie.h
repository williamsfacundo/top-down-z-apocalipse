#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <raylib.h>

#include "character.h"

namespace Z_APOCALIPSE
{
	class Zombie : public Character
	{
	private:		
		const float initialDamageTaken = 0.0f;		
		const float healthBarHeight = 10.0f;
		const Color healthBarColor = YELLOW;

		float damageTaken;
		float damageToDie;
		float velocity;		

		static short zombiesCreated;
	public:
		Zombie(Color characterColor, Vector2 position, float radius, Rectangle gameplayMap, float damageToDie, float velocity);
		~Zombie();

		void setDamageTaken(float damageTaken);
		void addDamageTaken(float damage);
		void setDamageToDie(float damageToDie);
		void setVelocity(float velocity);		

		float getDamageTaken();
		float getDamageToDie();
		float getVelocity();		
		Vector2 getZombieDirection(Vector2 playerPosition);
		static short getZombiesCreated();

		void update(Vector2 playerPosition);
		void movementUpdate(Vector2 playerPosition);
		void draw();
		bool isZombieDead();
		void drawZombieHealthBar();
		float calculateHealthBarWidth();
	};
}

#endif
