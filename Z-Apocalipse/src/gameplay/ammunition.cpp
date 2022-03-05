#include "ammunition.h"

namespace Z_APOCALIPSE 
{
	short Ammunition::amountOfAmmunitions = 0;

	Ammunition::Ammunition(Vector2 position, float radius)
	{
		setPosition(position);
		setRadius(radius);

		amountOfAmmunitions += 1;
	}		

	Ammunition::~Ammunition()
	{
		amountOfAmmunitions -= 1;
	}

	void Ammunition::setPosition(Vector2 position) 
	{
		this->position = position;
	}

	void Ammunition::setRadius(float radius) 
	{
		this->radius = radius;
	}

	Vector2 Ammunition::getPosition() 
	{
		return position;
	}

	float Ammunition::getRadius() 
	{
		return radius;
	}

	short Ammunition::getBulletsForPickUp() 
	{
		return bulletsForPickUp;
	}

	short Ammunition::getAmountOfAmmunitions() 
	{
		return amountOfAmmunitions;
	}

	void Ammunition::draw() 
	{
		DrawCircleV(getPosition(), getRadius(), ammunitionColor);
	}

	bool Ammunition::isCollidingWithCircle(Vector2 position, float radius) 
	{
		return CheckCollisionCircles(getPosition(), getRadius(), position, radius);
	}
}