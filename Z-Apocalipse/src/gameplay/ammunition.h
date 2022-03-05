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
	public:
		Ammunition(Vector2 position, float radius);		

		void setPosition(Vector2 position);
		void setRadius(float radius);

		Vector2 getPosition();
		float getRadius();
		short getBulletsForPickUp();

		void draw();
	};
}

#endif
