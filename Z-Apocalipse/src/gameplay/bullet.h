#ifndef BULLET_H
#define BULLET_H

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	enum class BulletsType { GUN };

	class Bullet
	{
	private:
		const Color gunTypeColor = BLACK;		
		
		const float initialVelocityDivider = 2.0f;

		BulletsType type;

		Vector2 position;		
		Vector2 direction;

		Color color;

		float initialVelocity;
		float velocity;
		float radius;

		static short bulletsCreated;
	public:
		Bullet(Vector2 position, Vector2 direction, BulletsType type, float radius);
		~Bullet();

		void setType(BulletsType type);
		void setPosition(Vector2 position);
		void setDirection(Vector2 direction);
		void setColor(Color color);
		void setInitialVelocity();
		void setVelocity(float velocity);
		void setRadius(float radius);		
		void setBulletsCreated(short bulletsCreated);

		BulletsType getType();
		Vector2 getPosition();
		Vector2 getDirection();
		Color getColor();
		float getInitialVelocity();
		float getVelocity();
		float getRadius();
		static short getBulletsCreated();

		void update();
		void draw();		
	};
}

#endif
