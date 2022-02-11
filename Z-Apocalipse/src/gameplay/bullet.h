#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

namespace Z_APOCALIPSE 
{
	class Bullet
	{
	private:
		const float initialVelocity = 250.0f;
		Vector2 position;		
		Vector2 direction;
		Color color;
		float velocity;
		float radius;
	public:
		Bullet(Vector2 position, Vector2 direction, Color color, float radius);

		void setPosition(Vector2 position);
		void setDirection(Vector2 direction);
		void setColor(Color color);
		void setVelocity(float velocity);
		void setRadius(float radius);

		Vector2 getPosition();
		Vector2 getDirection();
		Color getColor();
		float getVelocity();
		float getRadiu();

		void update();
		void draw();
	};
}

#endif
