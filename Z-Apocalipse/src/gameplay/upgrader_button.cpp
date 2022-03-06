#include "upgrader_button.h"

#include <raylib.h>

#include "..\math\math.h"

namespace Z_APOCALIPSE 
{
	UpgraderButton::UpgraderButton(const char* text, float radius, Color color, Vector2 position, Vector2 titlePosition)
	{
		setText(text);
		setRadius(radius);
		setFontSize();
		setColor(color);
		setCirclePosition(position);
		setTitlePosition(titlePosition);
	}

	void UpgraderButton::setText(const char* text)
	{
		this->text = text;
	}

	void UpgraderButton::setRadius(float radius) 
	{
		this->radius = radius;
	}

	void UpgraderButton::setFontSize()
	{
		fontSize = static_cast<int>(vectorMath::getScreenHypotenuse() / textSizeDivider);
	}

	void UpgraderButton::setColor(Color color) 
	{
		this->color = color;
	}

	void UpgraderButton::setCirclePosition(Vector2 position) 
	{
		circlePosition = position;
	}

	void UpgraderButton::setTitlePosition(Vector2 position)
	{
		titlePosition = position;
	}
	
	const char* UpgraderButton::getText() 
	{
		return text;
	}

	float UpgraderButton::getRadius() 
	{
		return radius;
	}

	int UpgraderButton::getFontSize()
	{
		return fontSize;
	}

	Color UpgraderButton::getColor() 
	{
		return color;
	}

	Vector2 UpgraderButton::getCirclePosition() 
	{
		return circlePosition;
	}

	Vector2 UpgraderButton::getTitlePosition()
	{
		return titlePosition;
	}

	bool UpgraderButton::buttonPressed()
	{
		return CheckCollisionPointCircle(GetMousePosition(), getCirclePosition(), getRadius()) && IsMouseButtonPressed(button);
	}

	void UpgraderButton::drawButton()
	{		
		DrawText( getText(), getTitlePosition().x, getTitlePosition().y, getFontSize(), getColor());
		DrawCircleV( getCirclePosition(), getRadius(), getColor());
	}
}