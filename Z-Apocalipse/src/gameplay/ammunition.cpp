#include "ammunition.h"

namespace Z_APOCALIPSE 
{
	Ammunition::Ammunition(Vector2 position, float radius)
	{
		setPosition(position);
		setRadius(radius);
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

	void Ammunition::draw() 
	{
		DrawCircleV(getPosition(), getRadius(), ammunitionColor);
	}
}