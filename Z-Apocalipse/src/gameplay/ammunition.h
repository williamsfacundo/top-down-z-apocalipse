#ifndef AMMUNITION_H
#define AMMUNITION_H

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	class Ammunition
	{
	private:
		const short bulletsForPickUp = 5;
		const Color ammunitionColor = YELLOW;

		Vector2 position;
		float radius;

		static short amountOfAmmunitions;
	public:
		Ammunition(Vector2 position, float radius);		
		~Ammunition();

		void setPosition(Vector2 position);
		void setRadius(float radius);

		Vector2 getPosition();
		float getRadius();
		short getBulletsForPickUp();
		static short getAmountOfAmmunitions();

		void draw();

		bool isCollidingWithCircle(Vector2 position, float radius);
	};
}

#endif
