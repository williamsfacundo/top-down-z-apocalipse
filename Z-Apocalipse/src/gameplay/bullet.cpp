#include "bullet.h"

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	Bullet::Bullet(Vector2 position, Vector2 direction, Color color, float radius) 
	{
		setPosition(position);
		setDirection(direction);
		setColor(color);
		setVelocity(initialVelocity);
		setRadius(radius);
	}

	void Bullet::setPosition(Vector2 position)
	{
		this->position = position;
	}

	void Bullet::setDirection(Vector2 direction) 
	{
		this->direction = direction;
	}

	void Bullet::setColor(Color color) 
	{
		this->color = color;
	}

	void Bullet::setVelocity(float velocity) 
	{
		this->velocity = velocity;
	}

	void Bullet::setRadius(float radius) 
	{
		this->radius = radius;
	}

	Vector2 Bullet::getPosition()
	{
		return position;
	}

	Vector2 Bullet::getDirection() 
	{
		return direction;
	}

	Color Bullet::getColor() 
	{
		return color;
	}

	float Bullet::getVelocity() 
	{
		return velocity;
	}

	float Bullet::getRadiu()
	{
		return radius;
	}

	void Bullet::update() 
	{
		position.x += velocity * direction.x * GetFrameTime();
		position.y += velocity * direction.y * GetFrameTime();
	}

	void Bullet::draw() 
	{
		DrawCircleV(position, radius, color);
	}
}