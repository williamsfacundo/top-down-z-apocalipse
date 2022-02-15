#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "character.h"

namespace Z_APOCALIPSE
{
	class Zombie : public Character
	{
	private:
		const float initialVelocity = 35.0f;
		const float initialDamageTaken = 0.0f;
		const float initialDamageToDie = 20.0f;

		float damageTaken;
		float damageToDie;
		float velocity;
		short level;

		static short zombiesCreated;
	public:
		Zombie(Color characterColor, Vector2 position, float radius, Rectangle gameplayMap, short level);
		~Zombie();

		void setDamageTaken(float damageTaken);
		void addDamageTaken(float damage);
		void setDamageToDie(float damageToDie);
		void setVelocity(float velocity);
		void setLevel(short level);

		float getDamageTaken();
		float getDamageToDie();
		float getVelocity();
		short getLevel();
		Vector2 getZombieDirection(Vector2 playerPosition);
		static short getZombiesCreated();

		void update(Vector2 playerPosition);
		void movementUpdate(Vector2 playerPosition);
		void draw();
		bool isZombieDead();
	};
}

#endif
