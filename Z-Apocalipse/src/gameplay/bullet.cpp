#include "bullet.h"

#include <raylib.h>

#include "..\math\math.h"

namespace Z_APOCALIPSE 
{
	short Bullet::bulletsCreated = 0;

	Bullet::Bullet(Vector2 position, Vector2 direction, BulletsType type, float radius)
	{
		setPosition(position);
		setDirection(direction);
		setInitialVelocity();
		setVelocity(getInitialVelocity());
		setType(type);

		switch (getType())
		{
		case BulletsType::GUN:

			setColor(gunTypeColor);
			setRadius(radius);
			break;
		default:
			break;
		}	
			
		bulletsCreated += 1;
	}

	Bullet::~Bullet() 
	{
		bulletsCreated -= 1;
	}

	void Bullet::setType(BulletsType type) 
	{
		this->type = type;
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

	void Bullet::setInitialVelocity()
	{
		initialVelocity = vectorMath::getScreenHypotenuse() / initialVelocityDivider;
	}

	void Bullet::setVelocity(float velocity) 
	{
		this->velocity = velocity;
	}

	void Bullet::setRadius(float radius) 
	{
		this->radius = radius;
	}

	void Bullet::setBulletsCreated(short bulletsCreated) 
	{
		this->bulletsCreated = bulletsCreated;
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

	float Bullet::getInitialVelocity() 
	{
		return initialVelocity;
	}

	float Bullet::getVelocity() 
	{
		return velocity;
	}

	float Bullet::getRadius()
	{
		return radius;
	}

	short Bullet::getBulletsCreated() 
	{
		return bulletsCreated;
	}

	BulletsType Bullet::getType() 
	{
		return type;
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